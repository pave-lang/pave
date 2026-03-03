#ifndef PAVE_PRINT
#define PAVE_PRINT

#include <stdio.h>

struct PrintVTable {
void (*print)(void* __self);
};

struct Print {
    const struct PrintVTable* vtable;
    void* instance;
};

#endif
