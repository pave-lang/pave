#ifdef _WIN32
    #include <windows.h>
    #include <fcntl.h>
    #include <io.h>
    #include <stdint.h>
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <errno.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fs.h"

int path_exists(const char *path) {
#ifdef _WIN32
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
    struct stat st;
    return stat(path, &st) == 0;
#endif
}

int create_directory(const char *path) {
#ifdef _WIN32
    if (!CreateDirectoryA(path, NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
        fprintf(stderr, "Failed to create directory '%s' (Error %lu)\n", path, GetLastError());
        return 0;
    }
#else
    if (mkdir(path, 0755) < 0 && errno != EEXIST) {
        fprintf(stderr, "Failed to create directory '%s'\n", path);
        perror("mkdir");
        return 0;
    }
#endif

    return 1;
}

#ifndef _WIN32
    #define PAVE_MEMSTREAM 1
#endif

#ifdef PAVE_MEMSTREAM

typedef struct MemFile {
    FILE *file;
    char *buffer;
    size_t length;
    struct MemFile *next;
} MemFile;

static MemFile *mem_files = NULL;

static MemFile *mem_file_find(FILE *file) {
    for (MemFile *entry = mem_files; entry != NULL; entry = entry->next) {
        if (entry->file == file) {
            return entry;
        }
    }
    return NULL;
}

#endif

static int mem_file_matches(const char *path, const char *data, size_t length) {
    FILE *existing = fopen(path, "r");
    if (existing == NULL) {
        return 0;
    }

    char chunk[8192];
    size_t offset = 0;
    int matches = 1;

    for (;;) {
        size_t got = fread(chunk, 1, sizeof(chunk), existing);
        if (got == 0) {
            break;
        }

        if (offset + got > length || memcmp(chunk, data + offset, got) != 0) {
            matches = 0;
            break;
        }

        offset += got;
    }

    fclose(existing);

    return matches && offset == length;
}

static int mem_file_write_now(const char *path, const char *data, size_t length) {
    if (mem_file_matches(path, data, length)) {
        return 0;
    }

    FILE *out = fopen(path, "w");
    if (out == NULL) {
        perror(path);
        return -1;
    }

    if (length > 0 && fwrite(data, 1, length, out) != length) {
        perror(path);
        fclose(out);
        return -1;
    }

    fclose(out);
    return 1;
}

// Saved files wait here until mem_file_flush, the last save of a path
// winning, so a file generated more than once in a run is written once, and
// not at all if it ends up as it was: its time stays the same, and builds
// that depend on it are not redone.
typedef struct PendingFile {
    char *path;
    char *data;
    size_t length;
    struct PendingFile *next;
} PendingFile;

static PendingFile *pending_files = NULL;

static int mem_file_write(const char *path, const char *data, size_t length) {
    PendingFile *entry = pending_files;
    while (entry != NULL && strcmp(entry->path, path) != 0) {
        entry = entry->next;
    }

    char *copy = malloc(length + 1);
    if (copy == NULL) {
        return -1;
    }
    memcpy(copy, data, length);

    if (entry == NULL) {
        entry = calloc(1, sizeof(PendingFile));
        size_t path_length = strlen(path);
        char *path_copy = malloc(path_length + 1);
        if (entry == NULL || path_copy == NULL) {
            free(entry);
            free(path_copy);
            free(copy);
            return -1;
        }
        memcpy(path_copy, path, path_length + 1);
        entry->path = path_copy;
        entry->next = pending_files;
        pending_files = entry;
    } else {
        free(entry->data);
    }

    entry->data = copy;
    entry->length = length;
    return 0;
}

int mem_file_flush(void) {
    int result = 0;
    while (pending_files != NULL) {
        PendingFile *entry = pending_files;
        pending_files = entry->next;
        if (mem_file_write_now(entry->path, entry->data, entry->length) < 0) {
            result = -1;
        }
        free(entry->path);
        free(entry->data);
        free(entry);
    }
    return result;
}

#ifdef _WIN32

static FILE *win_temp_file(void) {
    char dir[MAX_PATH + 1];
    DWORD dir_length = GetTempPathA(sizeof(dir), dir);
    if (dir_length == 0 || dir_length > MAX_PATH) {
        return NULL;
    }

    char path[MAX_PATH + 1];
    if (GetTempFileNameA(dir, "pav", 0, path) == 0) {
        return NULL;
    }

    HANDLE handle = CreateFileA(
        path,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE,
        NULL);

    if (handle == INVALID_HANDLE_VALUE) {
        DeleteFileA(path);
        return NULL;
    }

    int fd = _open_osfhandle((intptr_t)handle, _O_RDWR | _O_BINARY);
    if (fd < 0) {
        CloseHandle(handle);
        return NULL;
    }

    FILE *file = _fdopen(fd, "w+b");
    if (file == NULL) {
        _close(fd);
        return NULL;
    }

    setvbuf(file, NULL, _IOFBF, 64 * 1024);

    return file;
}

#endif

FILE *mem_file_open(void) {
#ifdef PAVE_MEMSTREAM
    MemFile *entry = malloc(sizeof(MemFile));
    if (entry == NULL) {
        return NULL;
    }

    entry->buffer = NULL;
    entry->length = 0;
    entry->file = open_memstream(&entry->buffer, &entry->length);
    if (entry->file == NULL) {
        free(entry);
        return NULL;
    }

    entry->next = mem_files;
    mem_files = entry;
    return entry->file;
#elif defined(_WIN32)
    FILE *file = win_temp_file();
    if (file != NULL) {
        return file;
    }

    return tmpfile();
#else
    return tmpfile();
#endif
}

int mem_file_save(FILE *file, const char *path) {
    if (file == NULL) {
        return -1;
    }

#ifdef PAVE_MEMSTREAM
    MemFile *entry = mem_file_find(file);
    if (entry == NULL) {
        return -1;
    }

    if (fflush(file) != 0) {
        return -1;
    }

    return mem_file_write(path, entry->buffer, entry->length);
#else
    if (fflush(file) != 0 || fseek(file, 0, SEEK_END) != 0) {
        return -1;
    }

    long size = ftell(file);
    if (size < 0) {
        return -1;
    }
    rewind(file);

    char *buffer = malloc((size_t)size + 1);
    if (buffer == NULL) {
        return -1;
    }

    size_t length = fread(buffer, 1, (size_t)size, file);
    int result = mem_file_write(path, buffer, length);

    free(buffer);
    return result;
#endif
}

void mem_file_close(FILE *file) {
    if (file == NULL) {
        return;
    }

#ifdef PAVE_MEMSTREAM
    MemFile **link = &mem_files;
    while (*link != NULL && (*link)->file != file) {
        link = &(*link)->next;
    }

    fclose(file);

    MemFile *entry = *link;
    if (entry != NULL) {
        *link = entry->next;
        free(entry->buffer);
        free(entry);
    }
#else
    fclose(file);
#endif
}
