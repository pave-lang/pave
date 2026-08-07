#ifndef PAVE_ITER_ENUMERATE_REF_STRUCT_TRAIT_INFO
#define PAVE_ITER_ENUMERATE_REF_STRUCT_TRAIT_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_StructTraitInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_StructTraitInfo {
    uintptr_t index;
    struct Iter_ref_StructTraitInfo iter;
};

#include <tuple_usize_ref_StructTraitInfo.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_StructTraitInfo__next(struct IterEnumerate_ref_StructTraitInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_StructTraitInfo IterEnumerate_ref_StructTraitInfo__value(struct IterEnumerate_ref_StructTraitInfo* self);

#endif
