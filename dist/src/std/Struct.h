#ifndef PAVE_STRUCT
#define PAVE_STRUCT

#include <stdint.h>
#include <stdbool.h>


#line 1 "src/std/Struct.pv"
struct StructVTable {
    #line 2 "src/std/Struct.pv"
struct slice_tuple_usize_str_TypeId (*get_fields)(void* __self);
    #line 3 "src/std/Struct.pv"
void* (*get_field)(void* __self, uintptr_t index);
    #line 4 "src/std/Struct.pv"
bool (*set_field)(void* __self, uintptr_t index, void* value);
};

#line 1 "src/std/Struct.pv"
struct Struct {
    const struct StructVTable* vtable;
    void* instance;
};

#endif
