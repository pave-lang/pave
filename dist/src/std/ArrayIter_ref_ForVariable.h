#ifndef PAVE_ARRAY_ITER_REF_FOR_VARIABLE
#define PAVE_ARRAY_ITER_REF_FOR_VARIABLE

#include <stdint.h>
#include <stdbool.h>

struct ForVariable;
struct IterEnumerate_ref_ForVariable;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ForVariable {
    intptr_t step;
    struct ForVariable* iter;
    struct ForVariable* start;
    struct ForVariable* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ForVariable ArrayIter_ref_ForVariable__new(struct ForVariable* start, struct ForVariable* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ForVariable ArrayIter_ref_ForVariable__reverse(struct ArrayIter_ref_ForVariable self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ForVariable ArrayIter_ref_ForVariable__skip(struct ArrayIter_ref_ForVariable self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ForVariable__next(struct ArrayIter_ref_ForVariable* self);

#line 43 "src/std/Array.pv"
struct ForVariable* ArrayIter_ref_ForVariable__value(struct ArrayIter_ref_ForVariable* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ForVariable ArrayIter_ref_ForVariable__enumerate(struct ArrayIter_ref_ForVariable self);

#endif
