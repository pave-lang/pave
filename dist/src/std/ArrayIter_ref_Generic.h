#ifndef PAVE_ARRAY_ITER_REF_GENERIC
#define PAVE_ARRAY_ITER_REF_GENERIC

#include <stdint.h>
#include <stdbool.h>

struct Generic;
struct IterEnumerate_ref_Generic;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_Generic {
    intptr_t step;
    struct Generic* iter;
    struct Generic* start;
    struct Generic* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_Generic ArrayIter_ref_Generic__new(struct Generic* start, struct Generic* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_Generic ArrayIter_ref_Generic__reverse(struct ArrayIter_ref_Generic self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_Generic ArrayIter_ref_Generic__skip(struct ArrayIter_ref_Generic self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_Generic__next(struct ArrayIter_ref_Generic* self);

#line 43 "src/std/Array.pv"
struct Generic* ArrayIter_ref_Generic__value(struct ArrayIter_ref_Generic* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Generic ArrayIter_ref_Generic__enumerate(struct ArrayIter_ref_Generic self);

#endif
