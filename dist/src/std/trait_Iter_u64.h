#ifndef PAVE_TRAIT_ITER_U64
#define PAVE_TRAIT_ITER_U64

#include <stdbool.h>
#include <stdint.h>

#include <std/trait_Iter_u64.h>

#line 1 "src/std/Iter.pv"
struct trait_Iter_u64VTable {
        #line 2 "src/std/Iter.pv"
bool (*next)(void* __self);
        #line 3 "src/std/Iter.pv"
uint64_t (*value)(void* __self);
};

#line 1 "src/std/Iter.pv"
struct trait_Iter_u64 {
    const struct trait_Iter_u64VTable* vtable;
    void* instance;
};

#endif
