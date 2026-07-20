#ifndef PAVE_PATH
#define PAVE_PATH

#ifdef _WIN32
    #include <windows.h>
    #include <ctype.h>
    #include <stdlib.h>

    #ifndef PATH_MAX_LEN
    #define PATH_MAX_LEN 4096
    #endif
#else
    #include <stdlib.h>
    #include <limits.h>

    #ifndef PATH_MAX_LEN
        #ifdef PATH_MAX
        #define PATH_MAX_LEN PATH_MAX
        #else
        #define PATH_MAX_LEN 4096
        #endif
    #endif
#endif

static inline const char* resolve_path(const char* path) {
    static char resolved[PATH_MAX_LEN];

#ifdef _WIN32
    DWORD len = GetFullPathNameA(path, PATH_MAX_LEN, resolved, NULL);

    if (len == 0 || len >= PATH_MAX_LEN) { return NULL; }

    if (len >= 2 && resolved[1] == ':' &&
        resolved[0] >= 'A' && resolved[0] <= 'Z') {
        resolved[0] = (char)tolower(resolved[0]);
    }

    for (DWORD i = 0; i < len; i++) {
        if (resolved[i] == '\\') { resolved[i] = '/'; }
    }
#else
    if (!realpath(path, resolved)) { return NULL; }
#endif

    return resolved;
}

#endif
