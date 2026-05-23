#ifndef PAVE_STRUCT_FIELD_INFO
#define PAVE_STRUCT_FIELD_INFO

#include <stdint.h>

#include <std/str.h>
#include <std/TypeId.h>

#line 1 "src/std/Struct.pv"
struct StructFieldInfo {
    uintptr_t index;
    struct str name;
    TypeId type_id;
    char const* type_name;
};

#endif
