#ifndef PAVE_ITER_REF_REF_EXPRESSION
#define PAVE_ITER_REF_REF_EXPRESSION

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Expression {
    intptr_t step;
    struct Expression** iter;
    struct Expression** start;
    struct Expression** end;
};

struct Iter_ref_ref_Expression;
#include <std/Iter_ref_ref_Expression.h>
#include <std/IterEnumerate_ref_ref_Expression.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Expression Iter_ref_ref_Expression__new(struct Expression** start, struct Expression** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Expression Iter_ref_ref_Expression__reverse(struct Iter_ref_ref_Expression self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Expression Iter_ref_ref_Expression__skip(struct Iter_ref_ref_Expression self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Expression__next(struct Iter_ref_ref_Expression* self);

#line 43 "src/std/Array.pv"
struct Expression** Iter_ref_ref_Expression__value(struct Iter_ref_ref_Expression* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Expression Iter_ref_ref_Expression__enumerate(struct Iter_ref_ref_Expression self);

#endif
