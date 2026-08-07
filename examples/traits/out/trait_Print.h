#ifndef PAVE_TRAIT_PRINT
#define PAVE_TRAIT_PRINT


struct trait_PrintVTable {
    void (*fn_print)(void* __self);
};

struct trait_Print {
    const struct trait_PrintVTable* vtable;
    void* instance;
};

#endif
