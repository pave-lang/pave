#ifndef PAVE_TRAIT_EQ_REF_STR
#define PAVE_TRAIT_EQ_REF_STR

#include <stdbool.h>

#include <std/trait_Eq_ref_str.h>
struct str;

#line 21 "src/std/Ops.pv"
struct trait_Eq_ref_strVTable {
    #line 22 "src/std/Ops.pv"
    bool (*fn_eq)(void* __self, struct str* other);
};

#line 21 "src/std/Ops.pv"
struct trait_Eq_ref_str {
    const struct trait_Eq_ref_strVTable* vtable;
    void* instance;
};

#endif
