#ifdef _WIN32
    #include <windows.h>
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
