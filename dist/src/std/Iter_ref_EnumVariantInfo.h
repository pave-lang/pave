#ifndef PAVE_ITER_REF_ENUM_VARIANT_INFO
#define PAVE_ITER_REF_ENUM_VARIANT_INFO

#include <stdint.h>
#include <stdbool.h>

struct EnumVariantInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_EnumVariantInfo {
    intptr_t step;
    struct EnumVariantInfo* iter;
    struct EnumVariantInfo* start;
    struct EnumVariantInfo* end;
};

#include <std/Iter_ref_EnumVariantInfo.h>
#include <std/IterEnumerate_ref_EnumVariantInfo.h>
struct EnumVariantInfo;
struct Iter_ref_EnumVariantInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_EnumVariantInfo Iter_ref_EnumVariantInfo__new(struct EnumVariantInfo* start, struct EnumVariantInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_EnumVariantInfo Iter_ref_EnumVariantInfo__reverse(struct Iter_ref_EnumVariantInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_EnumVariantInfo Iter_ref_EnumVariantInfo__skip(struct Iter_ref_EnumVariantInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_EnumVariantInfo__next(struct Iter_ref_EnumVariantInfo* self);

#line 43 "src/std/Array.pv"
struct EnumVariantInfo* Iter_ref_EnumVariantInfo__value(struct Iter_ref_EnumVariantInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_EnumVariantInfo Iter_ref_EnumVariantInfo__enumerate(struct Iter_ref_EnumVariantInfo self);

#endif
