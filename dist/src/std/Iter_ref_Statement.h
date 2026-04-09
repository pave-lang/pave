#ifndef PAVE_ITER_REF_STATEMENT
#define PAVE_ITER_REF_STATEMENT

#include <stdint.h>
#include <stdbool.h>

struct Statement;
struct IterEnumerate_ref_Statement;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_Statement {
    intptr_t step;
    struct Statement* iter;
    struct Statement* start;
    struct Statement* end;
};

#line 12 "src/std/Array.pv"
struct Iter_ref_Statement Iter_ref_Statement__new(struct Statement* start, struct Statement* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Statement Iter_ref_Statement__reverse(struct Iter_ref_Statement self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Statement Iter_ref_Statement__skip(struct Iter_ref_Statement self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Statement__next(struct Iter_ref_Statement* self);

#line 43 "src/std/Array.pv"
struct Statement* Iter_ref_Statement__value(struct Iter_ref_Statement* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Statement Iter_ref_Statement__enumerate(struct Iter_ref_Statement self);

#endif
