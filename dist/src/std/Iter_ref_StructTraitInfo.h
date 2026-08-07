#ifndef PAVE_ITER_REF_STRUCT_TRAIT_INFO
#define PAVE_ITER_REF_STRUCT_TRAIT_INFO

#include <stdint.h>
#include <stdbool.h>

struct StructTraitInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_StructTraitInfo {
    intptr_t step;
    struct StructTraitInfo* iter;
    struct StructTraitInfo* start;
    struct StructTraitInfo* end;
};

#include <std/IterEnumerate_ref_StructTraitInfo.h>
struct StructTraitInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_StructTraitInfo Iter_ref_StructTraitInfo__new(struct StructTraitInfo* start, struct StructTraitInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_StructTraitInfo Iter_ref_StructTraitInfo__reverse(struct Iter_ref_StructTraitInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_StructTraitInfo Iter_ref_StructTraitInfo__skip(struct Iter_ref_StructTraitInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_StructTraitInfo__next(struct Iter_ref_StructTraitInfo* self);

#line 43 "src/std/Array.pv"
struct StructTraitInfo* Iter_ref_StructTraitInfo__value(struct Iter_ref_StructTraitInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_StructTraitInfo Iter_ref_StructTraitInfo__enumerate(struct Iter_ref_StructTraitInfo self);

#endif
