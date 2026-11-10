#ifndef PAVE_ITER_REF_FUNCTION_TEMP
#define PAVE_ITER_REF_FUNCTION_TEMP

#include <stdint.h>
#include <stdbool.h>

struct FunctionTemp;

#line 4 "src/std/Array.pv"
struct Iter_ref_FunctionTemp {
    intptr_t step;
    struct FunctionTemp* iter;
    struct FunctionTemp* start;
    struct FunctionTemp* end;
};

#include <std/IterEnumerate_ref_FunctionTemp.h>
struct FunctionTemp;

#line 12 "src/std/Array.pv"
struct Iter_ref_FunctionTemp Iter_ref_FunctionTemp__new(struct FunctionTemp* start, struct FunctionTemp* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_FunctionTemp Iter_ref_FunctionTemp__reverse(struct Iter_ref_FunctionTemp self);

#line 33 "src/std/Array.pv"
struct Iter_ref_FunctionTemp Iter_ref_FunctionTemp__skip(struct Iter_ref_FunctionTemp self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_FunctionTemp__next(struct Iter_ref_FunctionTemp* self);

#line 43 "src/std/Array.pv"
struct FunctionTemp* Iter_ref_FunctionTemp__value(struct Iter_ref_FunctionTemp* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_FunctionTemp Iter_ref_FunctionTemp__enumerate(struct Iter_ref_FunctionTemp self);

#endif
