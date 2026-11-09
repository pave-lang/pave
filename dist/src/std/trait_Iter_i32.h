#ifndef PAVE_TRAIT_ITER_I32
#define PAVE_TRAIT_ITER_I32

#include <stdbool.h>
#include <stdint.h>


#line 1 "src/std/Iter.pv"
struct trait_Iter_i32VTable {
    #line 2 "src/std/Iter.pv"
    bool (*fn_next)(void* __self);
    #line 3 "src/std/Iter.pv"
    int32_t (*fn_value)(void* __self);
};

#line 1 "src/std/Iter.pv"
struct trait_Iter_i32 {
    const struct trait_Iter_i32VTable* vtable;
    void* instance;
};

#endif
