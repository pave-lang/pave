#ifndef PAVE_TRAIT_EQ_PTRC_CHAR
#define PAVE_TRAIT_EQ_PTRC_CHAR

#include <stdbool.h>

#include <std/trait_Eq_ptrc_char.h>

#line 21 "src/std/Ops.pv"
struct trait_Eq_ptrc_charVTable {
    #line 22 "src/std/Ops.pv"
    bool (*fn_eq)(void* __self, char const* other);
};

#line 21 "src/std/Ops.pv"
struct trait_Eq_ptrc_char {
    const struct trait_Eq_ptrc_charVTable* vtable;
    void* instance;
};

#endif
