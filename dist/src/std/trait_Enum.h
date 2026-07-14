#ifndef PAVE_TRAIT_ENUM
#define PAVE_TRAIT_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Enum.h>
#include <slice_EnumVariantInfo.h>

#line 22 "src/std/Enum.pv"
struct trait_EnumVTable {
    #line 23 "src/std/Enum.pv"
    struct slice_EnumVariantInfo (*fn_get_variants)(void* __self);
    #line 24 "src/std/Enum.pv"
    uintptr_t (*fn_get_variant_index)(void* __self);
    #line 25 "src/std/Enum.pv"
    void (*fn_set_variant)(void* __self, uintptr_t index);
    #line 26 "src/std/Enum.pv"
    void* (*fn_get_param)(void* __self, uintptr_t index);
    #line 27 "src/std/Enum.pv"
    bool (*fn_set_param)(void* __self, uintptr_t index, void* value);
};

#line 22 "src/std/Enum.pv"
struct trait_Enum {
    const struct trait_EnumVTable* vtable;
    void* instance;
};

#endif
