#ifndef PAVE_ITER_REF_DEFER_STATEMENT
#define PAVE_ITER_REF_DEFER_STATEMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct DeferStatement;

#line 4 "src/std/Array.pv"
struct Iter_ref_DeferStatement {
    intptr_t step;
    struct DeferStatement* iter;
    struct DeferStatement* start;
    struct DeferStatement* end;
};
struct DeferStatement;
struct Iter_ref_DeferStatement;
#include <std/Iter_ref_DeferStatement.h>
#include <std/IterEnumerate_ref_DeferStatement.h>


#line 12 "src/std/Array.pv"
struct Iter_ref_DeferStatement Iter_ref_DeferStatement__new(struct DeferStatement* start, struct DeferStatement* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_DeferStatement Iter_ref_DeferStatement__reverse(struct Iter_ref_DeferStatement self);

#line 33 "src/std/Array.pv"
struct Iter_ref_DeferStatement Iter_ref_DeferStatement__skip(struct Iter_ref_DeferStatement self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_DeferStatement__next(struct Iter_ref_DeferStatement* self);

#line 43 "src/std/Array.pv"
struct DeferStatement* Iter_ref_DeferStatement__value(struct Iter_ref_DeferStatement* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_DeferStatement Iter_ref_DeferStatement__enumerate(struct Iter_ref_DeferStatement self);

#endif
