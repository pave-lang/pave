#ifndef PAVE_TRAIT_EQ_STR
#define PAVE_TRAIT_EQ_STR

#include <stdbool.h>

#include <std/trait_Eq_str.h>
#include <std/str.h>

#line 21 "src/std/Ops.pv"
struct trait_Eq_strVTable {
    #line 22 "src/std/Ops.pv"
    bool (*fn_eq)(void* __self, struct str other);
};

#line 21 "src/std/Ops.pv"
struct trait_Eq_str {
    const struct trait_Eq_strVTable* vtable;
    void* instance;
};

#endif
