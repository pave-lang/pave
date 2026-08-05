#ifndef PAVE_ITER_REF_ENUM_VARIANT_PARAM_INFO
#define PAVE_ITER_REF_ENUM_VARIANT_PARAM_INFO

#include <stdint.h>
#include <stdbool.h>

struct EnumVariantParamInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_EnumVariantParamInfo {
    intptr_t step;
    struct EnumVariantParamInfo* iter;
    struct EnumVariantParamInfo* start;
    struct EnumVariantParamInfo* end;
};

#include <std/IterEnumerate_ref_EnumVariantParamInfo.h>
struct EnumVariantParamInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_EnumVariantParamInfo Iter_ref_EnumVariantParamInfo__new(struct EnumVariantParamInfo* start, struct EnumVariantParamInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_EnumVariantParamInfo Iter_ref_EnumVariantParamInfo__reverse(struct Iter_ref_EnumVariantParamInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_EnumVariantParamInfo Iter_ref_EnumVariantParamInfo__skip(struct Iter_ref_EnumVariantParamInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_EnumVariantParamInfo__next(struct Iter_ref_EnumVariantParamInfo* self);

#line 43 "src/std/Array.pv"
struct EnumVariantParamInfo* Iter_ref_EnumVariantParamInfo__value(struct Iter_ref_EnumVariantParamInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_EnumVariantParamInfo Iter_ref_EnumVariantParamInfo__enumerate(struct Iter_ref_EnumVariantParamInfo self);

#endif
