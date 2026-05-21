#ifndef PAVE_TRAIT_EQ_HASH
#define PAVE_TRAIT_EQ_HASH

#include <stdbool.h>

#include <std/trait_Eq_Hash.h>
#include <std/Hash.h>

#line 21 "src/std/Ops.pv"
struct trait_Eq_HashVTable {
    #line 22 "src/std/Ops.pv"
    bool (*fn_eq)(void* __self, Hash other);
};

#line 21 "src/std/Ops.pv"
struct trait_Eq_Hash {
    const struct trait_Eq_HashVTable* vtable;
    void* instance;
};

#endif
