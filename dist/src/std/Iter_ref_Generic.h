#ifndef PAVE_ITER_REF_GENERIC
#define PAVE_ITER_REF_GENERIC

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Generic;

#line 4 "src/std/Array.pv"
struct Iter_ref_Generic {
    intptr_t step;
    struct Generic* iter;
    struct Generic* start;
    struct Generic* end;
};

#include <std/Iter_ref_Generic.h>
#include <std/IterEnumerate_ref_Generic.h>
struct Generic;
struct Iter_ref_Generic;

#line 12 "src/std/Array.pv"
struct Iter_ref_Generic Iter_ref_Generic__new(struct Generic* start, struct Generic* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Generic Iter_ref_Generic__reverse(struct Iter_ref_Generic self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Generic Iter_ref_Generic__skip(struct Iter_ref_Generic self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Generic__next(struct Iter_ref_Generic* self);

#line 43 "src/std/Array.pv"
struct Generic* Iter_ref_Generic__value(struct Iter_ref_Generic* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Generic Iter_ref_Generic__enumerate(struct Iter_ref_Generic self);

#endif
