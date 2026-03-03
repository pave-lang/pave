#ifndef PAVE_ARRAY_ITER_REF_ELSE_STATEMENT
#define PAVE_ARRAY_ITER_REF_ELSE_STATEMENT

#include <stdint.h>
#include <stdbool.h>

struct ElseStatement;
struct IterEnumerate_ref_ElseStatement;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ElseStatement {
    intptr_t step;
    struct ElseStatement* iter;
    struct ElseStatement* start;
    struct ElseStatement* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ElseStatement ArrayIter_ref_ElseStatement__new(struct ElseStatement* start, struct ElseStatement* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ElseStatement ArrayIter_ref_ElseStatement__reverse(struct ArrayIter_ref_ElseStatement self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ElseStatement ArrayIter_ref_ElseStatement__skip(struct ArrayIter_ref_ElseStatement self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ElseStatement__next(struct ArrayIter_ref_ElseStatement* self);

#line 43 "src/std/Array.pv"
struct ElseStatement* ArrayIter_ref_ElseStatement__value(struct ArrayIter_ref_ElseStatement* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ElseStatement ArrayIter_ref_ElseStatement__enumerate(struct ArrayIter_ref_ElseStatement self);

#endif
