#ifndef PAVE_ARRAY_ITER_REF_DIAGNOSTIC
#define PAVE_ARRAY_ITER_REF_DIAGNOSTIC

#include <stdint.h>
#include <stdbool.h>

struct Diagnostic;
struct IterEnumerate_ref_Diagnostic;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_Diagnostic {
    intptr_t step;
    struct Diagnostic* iter;
    struct Diagnostic* start;
    struct Diagnostic* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_Diagnostic ArrayIter_ref_Diagnostic__new(struct Diagnostic* start, struct Diagnostic* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_Diagnostic ArrayIter_ref_Diagnostic__reverse(struct ArrayIter_ref_Diagnostic self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_Diagnostic ArrayIter_ref_Diagnostic__skip(struct ArrayIter_ref_Diagnostic self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_Diagnostic__next(struct ArrayIter_ref_Diagnostic* self);

#line 43 "src/std/Array.pv"
struct Diagnostic* ArrayIter_ref_Diagnostic__value(struct ArrayIter_ref_Diagnostic* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Diagnostic ArrayIter_ref_Diagnostic__enumerate(struct ArrayIter_ref_Diagnostic self);

#endif
