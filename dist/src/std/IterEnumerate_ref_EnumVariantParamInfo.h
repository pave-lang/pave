#ifndef PAVE_ITER_ENUMERATE_REF_ENUM_VARIANT_PARAM_INFO
#define PAVE_ITER_ENUMERATE_REF_ENUM_VARIANT_PARAM_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_EnumVariantParamInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_EnumVariantParamInfo {
    uintptr_t index;
    struct Iter_ref_EnumVariantParamInfo iter;
};

#include <tuple_usize_ref_EnumVariantParamInfo.h>
struct IterEnumerate_ref_EnumVariantParamInfo;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_EnumVariantParamInfo__next(struct IterEnumerate_ref_EnumVariantParamInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_EnumVariantParamInfo IterEnumerate_ref_EnumVariantParamInfo__value(struct IterEnumerate_ref_EnumVariantParamInfo* self);

#endif
