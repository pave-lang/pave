#ifndef PAVE_TRAIT_ANY
#define PAVE_TRAIT_ANY

#include <stdint.h>


#line 1 "src/std/Any.pv"
struct trait_AnyVTable {
    #line 2 "src/std/Any.pv"
    uintptr_t (*fn_size)(void* __self);
};

#line 1 "src/std/Any.pv"
struct trait_Any {
    const struct trait_AnyVTable* vtable;
    void* instance;
};

#endif
