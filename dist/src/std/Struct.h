#ifndef PAVE_STRUCT
#define PAVE_STRUCT

#include <stdint.h>
#include <stdbool.h>


#line 6 "src/std/Struct.pv"
struct StructVTable {
    #line 7 "src/std/Struct.pv"
struct slice_DynStructField (*get_fields)(void* __self);
    #line 8 "src/std/Struct.pv"
void* (*get_field)(void* __self, uintptr_t index);
    #line 9 "src/std/Struct.pv"
bool (*set_field)(void* __self, uintptr_t index, void* value);
};

#line 6 "src/std/Struct.pv"
struct Struct {
    const struct StructVTable* vtable;
    void* instance;
};

#endif
