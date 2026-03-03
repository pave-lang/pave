#ifndef PAVE_ARRAY_ITER_REF_REF_IMPL
#define PAVE_ARRAY_ITER_REF_REF_IMPL

#include <stdint.h>
#include <stdbool.h>

struct Impl;
struct IterEnumerate_ref_ref_Impl;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ref_Impl {
    intptr_t step;
    struct Impl** iter;
    struct Impl** start;
    struct Impl** end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ref_Impl ArrayIter_ref_ref_Impl__new(struct Impl** start, struct Impl** end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ref_Impl ArrayIter_ref_ref_Impl__reverse(struct ArrayIter_ref_ref_Impl self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ref_Impl ArrayIter_ref_ref_Impl__skip(struct ArrayIter_ref_ref_Impl self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ref_Impl__next(struct ArrayIter_ref_ref_Impl* self);

#line 43 "src/std/Array.pv"
struct Impl** ArrayIter_ref_ref_Impl__value(struct ArrayIter_ref_ref_Impl* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Impl ArrayIter_ref_ref_Impl__enumerate(struct ArrayIter_ref_ref_Impl self);

#endif
