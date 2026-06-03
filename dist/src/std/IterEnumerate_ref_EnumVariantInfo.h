#ifndef PAVE_ITER_ENUMERATE_REF_ENUM_VARIANT_INFO
#define PAVE_ITER_ENUMERATE_REF_ENUM_VARIANT_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_EnumVariantInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_EnumVariantInfo {
    uintptr_t index;
    struct Iter_ref_EnumVariantInfo iter;
};

#include <tuple_usize_ref_EnumVariantInfo.h>
struct IterEnumerate_ref_EnumVariantInfo;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_EnumVariantInfo__next(struct IterEnumerate_ref_EnumVariantInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_EnumVariantInfo IterEnumerate_ref_EnumVariantInfo__value(struct IterEnumerate_ref_EnumVariantInfo* self);

#endif
