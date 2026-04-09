#ifndef PAVE_ITER_REF_SCOPE
#define PAVE_ITER_REF_SCOPE

#include <stdint.h>
#include <stdbool.h>

struct Scope;
struct IterEnumerate_ref_Scope;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_Scope {
    intptr_t step;
    struct Scope* iter;
    struct Scope* start;
    struct Scope* end;
};

#line 12 "src/std/Array.pv"
struct Iter_ref_Scope Iter_ref_Scope__new(struct Scope* start, struct Scope* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Scope Iter_ref_Scope__reverse(struct Iter_ref_Scope self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Scope Iter_ref_Scope__skip(struct Iter_ref_Scope self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Scope__next(struct Iter_ref_Scope* self);

#line 43 "src/std/Array.pv"
struct Scope* Iter_ref_Scope__value(struct Iter_ref_Scope* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Scope Iter_ref_Scope__enumerate(struct Iter_ref_Scope self);

#endif
