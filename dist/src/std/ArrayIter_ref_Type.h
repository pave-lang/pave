#ifndef PAVE_ARRAY_ITER_REF_TYPE
#define PAVE_ARRAY_ITER_REF_TYPE

#include <stdint.h>
#include <stdbool.h>

struct Type;
struct IterEnumerate_ref_Type;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_Type {
    intptr_t step;
    struct Type* iter;
    struct Type* start;
    struct Type* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_Type ArrayIter_ref_Type__new(struct Type* start, struct Type* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_Type ArrayIter_ref_Type__reverse(struct ArrayIter_ref_Type self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_Type ArrayIter_ref_Type__skip(struct ArrayIter_ref_Type self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_Type__next(struct ArrayIter_ref_Type* self);

#line 43 "src/std/Array.pv"
struct Type* ArrayIter_ref_Type__value(struct ArrayIter_ref_Type* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Type ArrayIter_ref_Type__enumerate(struct ArrayIter_ref_Type self);

#endif
