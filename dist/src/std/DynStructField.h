#ifndef PAVE_DYN_STRUCT_FIELD
#define PAVE_DYN_STRUCT_FIELD

#include <std/str.h>
#include <stdint.h>
#include <std/TypeId.h>

#line 1 "src/std/DynStruct.pv"
struct DynStructField {
    struct str name;
    TypeId typeid;
};

#endif
