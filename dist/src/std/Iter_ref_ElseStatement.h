#ifndef PAVE_ITER_REF_ELSE_STATEMENT
#define PAVE_ITER_REF_ELSE_STATEMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct ElseStatement;

#line 4 "src/std/Array.pv"
struct Iter_ref_ElseStatement {
    intptr_t step;
    struct ElseStatement* iter;
    struct ElseStatement* start;
    struct ElseStatement* end;
};

struct ElseStatement;
struct Iter_ref_ElseStatement;
#include <std/Iter_ref_ElseStatement.h>
#include <std/IterEnumerate_ref_ElseStatement.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_ElseStatement Iter_ref_ElseStatement__new(struct ElseStatement* start, struct ElseStatement* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ElseStatement Iter_ref_ElseStatement__reverse(struct Iter_ref_ElseStatement self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ElseStatement Iter_ref_ElseStatement__skip(struct Iter_ref_ElseStatement self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ElseStatement__next(struct Iter_ref_ElseStatement* self);

#line 43 "src/std/Array.pv"
struct ElseStatement* Iter_ref_ElseStatement__value(struct Iter_ref_ElseStatement* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ElseStatement Iter_ref_ElseStatement__enumerate(struct Iter_ref_ElseStatement self);

#endif
