#ifndef PAVE_ITER_ENUMERATE_REF_STRUCT_FIELD_INFO
#define PAVE_ITER_ENUMERATE_REF_STRUCT_FIELD_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_StructFieldInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_StructFieldInfo {
    uintptr_t index;
    struct Iter_ref_StructFieldInfo iter;
};

#include <tuple_usize_ref_StructFieldInfo.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_StructFieldInfo__next(struct IterEnumerate_ref_StructFieldInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_StructFieldInfo IterEnumerate_ref_StructFieldInfo__value(struct IterEnumerate_ref_StructFieldInfo* self);

#endif
