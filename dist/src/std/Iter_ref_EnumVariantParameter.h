#ifndef PAVE_ITER_REF_ENUM_VARIANT_PARAMETER
#define PAVE_ITER_REF_ENUM_VARIANT_PARAMETER

#include <stdint.h>
#include <stdbool.h>

struct EnumVariantParameter;
struct IterEnumerate_ref_EnumVariantParameter;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_EnumVariantParameter {
    intptr_t step;
    struct EnumVariantParameter* iter;
    struct EnumVariantParameter* start;
    struct EnumVariantParameter* end;
};

#line 12 "src/std/Array.pv"
struct Iter_ref_EnumVariantParameter Iter_ref_EnumVariantParameter__new(struct EnumVariantParameter* start, struct EnumVariantParameter* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_EnumVariantParameter Iter_ref_EnumVariantParameter__reverse(struct Iter_ref_EnumVariantParameter self);

#line 33 "src/std/Array.pv"
struct Iter_ref_EnumVariantParameter Iter_ref_EnumVariantParameter__skip(struct Iter_ref_EnumVariantParameter self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_EnumVariantParameter__next(struct Iter_ref_EnumVariantParameter* self);

#line 43 "src/std/Array.pv"
struct EnumVariantParameter* Iter_ref_EnumVariantParameter__value(struct Iter_ref_EnumVariantParameter* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_EnumVariantParameter Iter_ref_EnumVariantParameter__enumerate(struct Iter_ref_EnumVariantParameter self);

#endif
