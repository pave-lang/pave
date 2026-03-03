#ifndef PAVE_DYN_STRUCT
#define PAVE_DYN_STRUCT

#include <stdint.h>
#include <stdbool.h>


#line 6 "src/std/DynStruct.pv"
struct DynStructVTable {
    #line 7 "src/std/DynStruct.pv"
struct slice_DynStructField (*get_fields)(void* __self);
    #line 8 "src/std/DynStruct.pv"
void* (*get_field)(void* __self, uintptr_t index);
    #line 9 "src/std/DynStruct.pv"
bool (*set_field)(void* __self, uintptr_t index, void* value);
};

#line 6 "src/std/DynStruct.pv"
struct DynStruct {
    const struct DynStructVTable* vtable;
    void* instance;
};

#endif
