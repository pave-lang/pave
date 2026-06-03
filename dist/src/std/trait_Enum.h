#ifndef PAVE_TRAIT_ENUM
#define PAVE_TRAIT_ENUM

#include <stdint.h>

#include <std/trait_Enum.h>
#include <slice_EnumVariantInfo.h>

#line 6 "src/std/Enum.pv"
struct trait_EnumVTable {
    #line 7 "src/std/Enum.pv"
    struct slice_EnumVariantInfo (*fn_get_variants)(void* __self);
    #line 8 "src/std/Enum.pv"
    uintptr_t (*fn_get_variant_index)(void* __self);
    #line 9 "src/std/Enum.pv"
    void (*fn_set_variant)(void* __self, uintptr_t index);
};

#line 6 "src/std/Enum.pv"
struct trait_Enum {
    const struct trait_EnumVTable* vtable;
    void* instance;
};

#endif
