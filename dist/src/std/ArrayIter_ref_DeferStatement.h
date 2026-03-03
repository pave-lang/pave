#ifndef PAVE_ARRAY_ITER_REF_DEFER_STATEMENT
#define PAVE_ARRAY_ITER_REF_DEFER_STATEMENT

#include <stdint.h>
#include <stdbool.h>

struct DeferStatement;
struct IterEnumerate_ref_DeferStatement;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_DeferStatement {
    intptr_t step;
    struct DeferStatement* iter;
    struct DeferStatement* start;
    struct DeferStatement* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_DeferStatement ArrayIter_ref_DeferStatement__new(struct DeferStatement* start, struct DeferStatement* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_DeferStatement ArrayIter_ref_DeferStatement__reverse(struct ArrayIter_ref_DeferStatement self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_DeferStatement ArrayIter_ref_DeferStatement__skip(struct ArrayIter_ref_DeferStatement self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_DeferStatement__next(struct ArrayIter_ref_DeferStatement* self);

#line 43 "src/std/Array.pv"
struct DeferStatement* ArrayIter_ref_DeferStatement__value(struct ArrayIter_ref_DeferStatement* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_DeferStatement ArrayIter_ref_DeferStatement__enumerate(struct ArrayIter_ref_DeferStatement self);

#endif
