#ifndef PAVE_TRAIT_STRUCT
#define PAVE_TRAIT_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Struct.h>
#include <slice_tuple_usize_str_TypeId.h>
#line 1 "src/std/Struct.pv"
struct trait_StructVTable {
    #line 2 "src/std/Struct.pv"
struct slice_tuple_usize_str_TypeId (*get_fields)(void* __self);
    #line 3 "src/std/Struct.pv"
void* (*get_field)(void* __self, uintptr_t index);
    #line 4 "src/std/Struct.pv"
bool (*set_field)(void* __self, uintptr_t index, void* value);
};

#line 1 "src/std/Struct.pv"
struct trait_Struct {
    const struct trait_StructVTable* vtable;
    void* instance;
};

#endif
