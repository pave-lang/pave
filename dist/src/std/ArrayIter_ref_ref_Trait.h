#ifndef PAVE_ARRAY_ITER_REF_REF_TRAIT
#define PAVE_ARRAY_ITER_REF_REF_TRAIT

#include <stdint.h>
#include <stdbool.h>

struct Trait;
struct IterEnumerate_ref_ref_Trait;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ref_Trait {
    intptr_t step;
    struct Trait** iter;
    struct Trait** start;
    struct Trait** end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ref_Trait ArrayIter_ref_ref_Trait__new(struct Trait** start, struct Trait** end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ref_Trait ArrayIter_ref_ref_Trait__reverse(struct ArrayIter_ref_ref_Trait self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ref_Trait ArrayIter_ref_ref_Trait__skip(struct ArrayIter_ref_ref_Trait self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ref_Trait__next(struct ArrayIter_ref_ref_Trait* self);

#line 43 "src/std/Array.pv"
struct Trait** ArrayIter_ref_ref_Trait__value(struct ArrayIter_ref_ref_Trait* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Trait ArrayIter_ref_ref_Trait__enumerate(struct ArrayIter_ref_ref_Trait self);

#endif
