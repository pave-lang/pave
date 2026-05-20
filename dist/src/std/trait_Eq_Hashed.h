#ifndef PAVE_TRAIT_EQ_HASHED
#define PAVE_TRAIT_EQ_HASHED

#include <stdbool.h>

#include <std/trait_Eq_Hashed.h>
#include <std/Hashed.h>

#line 21 "src/std/Ops.pv"
struct trait_Eq_HashedVTable {
    #line 22 "src/std/Ops.pv"
    bool (*fn_eq)(void* __self, Hashed other);
};

#line 21 "src/std/Ops.pv"
struct trait_Eq_Hashed {
    const struct trait_Eq_HashedVTable* vtable;
    void* instance;
};

#endif
