#ifndef PAVE_ITER_REF_FUNCTION_SCOPE
#define PAVE_ITER_REF_FUNCTION_SCOPE

#include <stdint.h>
#include <stdbool.h>

struct FunctionScope;

#line 4 "src/std/Array.pv"
struct Iter_ref_FunctionScope {
    intptr_t step;
    struct FunctionScope* iter;
    struct FunctionScope* start;
    struct FunctionScope* end;
};

#include <std/Iter_ref_FunctionScope.h>
#include <std/IterEnumerate_ref_FunctionScope.h>
struct FunctionScope;
struct Iter_ref_FunctionScope;

#line 12 "src/std/Array.pv"
struct Iter_ref_FunctionScope Iter_ref_FunctionScope__new(struct FunctionScope* start, struct FunctionScope* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_FunctionScope Iter_ref_FunctionScope__reverse(struct Iter_ref_FunctionScope self);

#line 33 "src/std/Array.pv"
struct Iter_ref_FunctionScope Iter_ref_FunctionScope__skip(struct Iter_ref_FunctionScope self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_FunctionScope__next(struct Iter_ref_FunctionScope* self);

#line 43 "src/std/Array.pv"
struct FunctionScope* Iter_ref_FunctionScope__value(struct Iter_ref_FunctionScope* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_FunctionScope Iter_ref_FunctionScope__enumerate(struct Iter_ref_FunctionScope self);

#endif
