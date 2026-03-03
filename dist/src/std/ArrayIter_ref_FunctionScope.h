#ifndef PAVE_ARRAY_ITER_REF_FUNCTION_SCOPE
#define PAVE_ARRAY_ITER_REF_FUNCTION_SCOPE

#include <stdint.h>
#include <stdbool.h>

struct FunctionScope;
struct IterEnumerate_ref_FunctionScope;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_FunctionScope {
    intptr_t step;
    struct FunctionScope* iter;
    struct FunctionScope* start;
    struct FunctionScope* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_FunctionScope ArrayIter_ref_FunctionScope__new(struct FunctionScope* start, struct FunctionScope* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_FunctionScope ArrayIter_ref_FunctionScope__reverse(struct ArrayIter_ref_FunctionScope self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_FunctionScope ArrayIter_ref_FunctionScope__skip(struct ArrayIter_ref_FunctionScope self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_FunctionScope__next(struct ArrayIter_ref_FunctionScope* self);

#line 43 "src/std/Array.pv"
struct FunctionScope* ArrayIter_ref_FunctionScope__value(struct ArrayIter_ref_FunctionScope* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_FunctionScope ArrayIter_ref_FunctionScope__enumerate(struct ArrayIter_ref_FunctionScope self);

#endif
