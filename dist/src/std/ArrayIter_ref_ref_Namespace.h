#ifndef PAVE_ARRAY_ITER_REF_REF_NAMESPACE
#define PAVE_ARRAY_ITER_REF_REF_NAMESPACE

#include <stdint.h>
#include <stdbool.h>

struct Namespace;
struct IterEnumerate_ref_ref_Namespace;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ref_Namespace {
    intptr_t step;
    struct Namespace** iter;
    struct Namespace** start;
    struct Namespace** end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ref_Namespace ArrayIter_ref_ref_Namespace__new(struct Namespace** start, struct Namespace** end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ref_Namespace ArrayIter_ref_ref_Namespace__reverse(struct ArrayIter_ref_ref_Namespace self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ref_Namespace ArrayIter_ref_ref_Namespace__skip(struct ArrayIter_ref_ref_Namespace self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ref_Namespace__next(struct ArrayIter_ref_ref_Namespace* self);

#line 43 "src/std/Array.pv"
struct Namespace** ArrayIter_ref_ref_Namespace__value(struct ArrayIter_ref_ref_Namespace* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Namespace ArrayIter_ref_ref_Namespace__enumerate(struct ArrayIter_ref_ref_Namespace self);

#endif
