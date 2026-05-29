#ifndef PAVE_TRAIT_SIZED
#define PAVE_TRAIT_SIZED

#include <stdint.h>

#include <std/trait_Sized.h>

#line 1 "src/std/Sized.pv"
struct trait_SizedVTable {
    #line 2 "src/std/Sized.pv"
    uintptr_t (*fn_size)(void* __self);
};

#line 1 "src/std/Sized.pv"
struct trait_Sized {
    const struct trait_SizedVTable* vtable;
    void* instance;
};

#endif
