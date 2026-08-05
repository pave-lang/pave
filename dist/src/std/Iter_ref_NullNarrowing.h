#ifndef PAVE_ITER_REF_NULL_NARROWING
#define PAVE_ITER_REF_NULL_NARROWING

#include <stdint.h>
#include <stdbool.h>

struct NullNarrowing;

#line 4 "src/std/Array.pv"
struct Iter_ref_NullNarrowing {
    intptr_t step;
    struct NullNarrowing* iter;
    struct NullNarrowing* start;
    struct NullNarrowing* end;
};

#include <std/IterEnumerate_ref_NullNarrowing.h>
struct NullNarrowing;

#line 12 "src/std/Array.pv"
struct Iter_ref_NullNarrowing Iter_ref_NullNarrowing__new(struct NullNarrowing* start, struct NullNarrowing* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_NullNarrowing Iter_ref_NullNarrowing__reverse(struct Iter_ref_NullNarrowing self);

#line 33 "src/std/Array.pv"
struct Iter_ref_NullNarrowing Iter_ref_NullNarrowing__skip(struct Iter_ref_NullNarrowing self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_NullNarrowing__next(struct Iter_ref_NullNarrowing* self);

#line 43 "src/std/Array.pv"
struct NullNarrowing* Iter_ref_NullNarrowing__value(struct Iter_ref_NullNarrowing* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_NullNarrowing Iter_ref_NullNarrowing__enumerate(struct Iter_ref_NullNarrowing self);

#endif
