#ifndef PAVE_TRAIT_PRINT
#define PAVE_TRAIT_PRINT

#include <traits/trait_Print.h>

struct trait_PrintVTable {
    void (*print)(void* __self);
};

struct trait_Print {
    const struct trait_PrintVTable* vtable;
    void* instance;
};

#endif
