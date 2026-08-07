#ifndef PAVE_PIPES
#define PAVE_PIPES

#ifdef _WIN32
    #include <windows.h>
    typedef HANDLE pipe_t;
    #define INVALID_PIPE INVALID_HANDLE_VALUE
#else
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/socket.h>
    #include <sys/un.h>
    typedef int pipe_t;
    #define INVALID_PIPE -1
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static inline int read_pipe(pipe_t pipe, char *buf, int len) {
#ifdef _WIN32
    DWORD total = 0;
    DWORD n;
    while (total < len) {
        if (!ReadFile(pipe, buf + total, len - total, &n, NULL) || n == 0) { return 0;}
        total += n;
    }
    return 1;
#else
    int total = 0;
    int n;
    while (total < len) {
        n = read(pipe, buf + total, len - total);
        if (n <= 0) { return 0; }
        total += n;
    }
    return 1;
#endif
}

static inline int write_pipe(pipe_t pipe, const char *data, int len) {
#ifdef _WIN32
    DWORD written;
    if (!WriteFile(pipe, data, len, &written, NULL)) { return 0; }
    return 1;
#else
    int total = 0, n;
    while (total < len) {
        n = write(pipe, data + total, len - total);
        if (n <= 0) { return 0; }
        total += n;
    }
    return 1;
#endif
}

static inline void flush_pipe(pipe_t pipe) {
#ifdef _WIN32
    FlushFileBuffers(pipe);
#else
    (void)pipe;
#endif
}

static inline void close_pipe(pipe_t pipe) {
#ifdef _WIN32
    CloseHandle(pipe);
#else
    close(pipe);
#endif
}

static inline pipe_t open_pipe(const char *pipe_name) {
#ifdef _WIN32
    pipe_t pipe = CreateFileA(
        pipe_name,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (pipe == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Failed to open pipe (%lu)\n", GetLastError());
        return INVALID_PIPE;
    }

    DWORD mode = PIPE_READMODE_BYTE;
    if (!SetNamedPipeHandleState(pipe, &mode, NULL, NULL)) {
        fprintf(stderr, "Failed to set pipe mode (%lu)\n", GetLastError());
        CloseHandle(pipe);
        return INVALID_PIPE;
    }
    
    return pipe;
#else
    pipe_t fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return INVALID_PIPE;
    }

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, pipe_name, sizeof(addr.sun_path) - 1);

    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Failed to connect to pipe: %s\n", pipe_name);
        perror("connect");
        close(fd);
        return INVALID_PIPE;
    }

    return fd;
#endif
}

static inline pipe_t get_stdin_pipe() {
#ifdef _WIN32
    return GetStdHandle(STD_INPUT_HANDLE);
#else
    return STDIN_FILENO;
#endif
}


static inline pipe_t get_stdout_pipe() {
#ifdef _WIN32
    return GetStdHandle(STD_OUTPUT_HANDLE);
#else
    return STDOUT_FILENO;
#endif
}

#endif