#ifndef PAVE_TRAIT_STRUCT
#define PAVE_TRAIT_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Struct.h>
#include <slice_StructFieldInfo.h>

#line 8 "src/std/Struct.pv"
struct trait_StructVTable {
    #line 9 "src/std/Struct.pv"
    struct slice_StructFieldInfo (*fn_get_fields)(void* __self);
    #line 10 "src/std/Struct.pv"
    void* (*fn_get_field)(void* __self, uintptr_t index);
    #line 11 "src/std/Struct.pv"
    bool (*fn_set_field)(void* __self, uintptr_t index, void* value);
};

#line 8 "src/std/Struct.pv"
struct trait_Struct {
    const struct trait_StructVTable* vtable;
    void* instance;
};

#endif
