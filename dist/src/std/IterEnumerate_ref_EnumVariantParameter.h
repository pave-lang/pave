#ifndef PAVE_ITER_ENUMERATE_REF_ENUM_VARIANT_PARAMETER
#define PAVE_ITER_ENUMERATE_REF_ENUM_VARIANT_PARAMETER

#include <stdint.h>
#include <std/ArrayIter_ref_EnumVariantParameter.h>
#include <stdbool.h>

struct EnumVariantParameter;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_EnumVariantParameter {
    uintptr_t index;
    struct ArrayIter_ref_EnumVariantParameter iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_EnumVariantParameter__next(struct IterEnumerate_ref_EnumVariantParameter* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_EnumVariantParameter IterEnumerate_ref_EnumVariantParameter__value(struct IterEnumerate_ref_EnumVariantParameter* self);

#endif
