#ifndef PAVE_ITER_REF_REF_TRAIT_FORMAT
#define PAVE_ITER_REF_REF_TRAIT_FORMAT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Format.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_trait_Format {
    intptr_t step;
    struct trait_Format* iter;
    struct trait_Format* start;
    struct trait_Format* end;
};

#include <std/trait_Format.h>
#include <std/IterEnumerate_ref_ref_trait_Format.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_trait_Format Iter_ref_ref_trait_Format__new(struct trait_Format* start, struct trait_Format* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_trait_Format Iter_ref_ref_trait_Format__reverse(struct Iter_ref_ref_trait_Format self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_trait_Format Iter_ref_ref_trait_Format__skip(struct Iter_ref_ref_trait_Format self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_trait_Format__next(struct Iter_ref_ref_trait_Format* self);

#line 43 "src/std/Array.pv"
struct trait_Format* Iter_ref_ref_trait_Format__value(struct Iter_ref_ref_trait_Format* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_trait_Format Iter_ref_ref_trait_Format__enumerate(struct Iter_ref_ref_trait_Format self);

#endif
