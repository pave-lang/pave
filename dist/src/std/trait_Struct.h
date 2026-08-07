#ifndef PAVE_TRAIT_STRUCT
#define PAVE_TRAIT_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <slice_StructFieldInfo.h>
#include <slice_StructTraitInfo.h>

#line 13 "src/std/Struct.pv"
struct trait_StructVTable {
    #line 14 "src/std/Struct.pv"
    struct slice_StructFieldInfo (*fn_get_fields)(void* __self);
    #line 15 "src/std/Struct.pv"
    struct slice_StructTraitInfo (*fn_get_traits)(void* __self);
    #line 16 "src/std/Struct.pv"
    void* (*fn_get_field)(void* __self, uintptr_t index);
    #line 17 "src/std/Struct.pv"
    bool (*fn_set_field)(void* __self, uintptr_t index, void* value);
};

#line 13 "src/std/Struct.pv"
struct trait_Struct {
    const struct trait_StructVTable* vtable;
    void* instance;
};

#endif
