#ifndef PAVE_ARRAY_ITER_REF_REF_TUPLE
#define PAVE_ARRAY_ITER_REF_REF_TUPLE

#include <stdint.h>
#include <stdbool.h>

struct Tuple;
struct IterEnumerate_ref_ref_Tuple;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ref_Tuple {
    intptr_t step;
    struct Tuple** iter;
    struct Tuple** start;
    struct Tuple** end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ref_Tuple ArrayIter_ref_ref_Tuple__new(struct Tuple** start, struct Tuple** end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ref_Tuple ArrayIter_ref_ref_Tuple__reverse(struct ArrayIter_ref_ref_Tuple self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ref_Tuple ArrayIter_ref_ref_Tuple__skip(struct ArrayIter_ref_ref_Tuple self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ref_Tuple__next(struct ArrayIter_ref_ref_Tuple* self);

#line 43 "src/std/Array.pv"
struct Tuple** ArrayIter_ref_ref_Tuple__value(struct ArrayIter_ref_ref_Tuple* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Tuple ArrayIter_ref_ref_Tuple__enumerate(struct ArrayIter_ref_ref_Tuple self);

#endif
