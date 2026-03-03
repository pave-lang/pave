#ifndef PAVE_ARRAY_ITER_REF_REF_EXPRESSION
#define PAVE_ARRAY_ITER_REF_REF_EXPRESSION

#include <stdint.h>
#include <stdbool.h>

struct Expression;
struct IterEnumerate_ref_ref_Expression;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ref_Expression {
    intptr_t step;
    struct Expression** iter;
    struct Expression** start;
    struct Expression** end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ref_Expression ArrayIter_ref_ref_Expression__new(struct Expression** start, struct Expression** end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ref_Expression ArrayIter_ref_ref_Expression__reverse(struct ArrayIter_ref_ref_Expression self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ref_Expression ArrayIter_ref_ref_Expression__skip(struct ArrayIter_ref_ref_Expression self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ref_Expression__next(struct ArrayIter_ref_ref_Expression* self);

#line 43 "src/std/Array.pv"
struct Expression** ArrayIter_ref_ref_Expression__value(struct ArrayIter_ref_ref_Expression* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Expression ArrayIter_ref_ref_Expression__enumerate(struct ArrayIter_ref_ref_Expression self);

#endif
