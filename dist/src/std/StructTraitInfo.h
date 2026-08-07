#ifndef PAVE_STRUCT_TRAIT_INFO
#define PAVE_STRUCT_TRAIT_INFO

#include <std/TypeId.h>

#line 8 "src/std/Struct.pv"
struct StructTraitInfo {
    TypeId type_id;
    void* vtable;
};

#endif
