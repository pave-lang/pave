#ifndef PAVE_ARRAY_ITER_REF_TOKEN
#define PAVE_ARRAY_ITER_REF_TOKEN

#include <stdint.h>
#include <stdbool.h>

struct Token;
struct IterEnumerate_ref_Token;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_Token {
    intptr_t step;
    struct Token* iter;
    struct Token* start;
    struct Token* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_Token ArrayIter_ref_Token__new(struct Token* start, struct Token* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_Token ArrayIter_ref_Token__reverse(struct ArrayIter_ref_Token self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_Token ArrayIter_ref_Token__skip(struct ArrayIter_ref_Token self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_Token__next(struct ArrayIter_ref_Token* self);

#line 43 "src/std/Array.pv"
struct Token* ArrayIter_ref_Token__value(struct ArrayIter_ref_Token* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Token ArrayIter_ref_Token__enumerate(struct ArrayIter_ref_Token self);

#endif
