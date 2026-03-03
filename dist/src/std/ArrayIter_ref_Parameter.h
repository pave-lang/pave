#ifndef PAVE_ARRAY_ITER_REF_PARAMETER
#define PAVE_ARRAY_ITER_REF_PARAMETER

#include <stdint.h>
#include <stdbool.h>

struct Parameter;
struct IterEnumerate_ref_Parameter;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_Parameter {
    intptr_t step;
    struct Parameter* iter;
    struct Parameter* start;
    struct Parameter* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_Parameter ArrayIter_ref_Parameter__new(struct Parameter* start, struct Parameter* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_Parameter ArrayIter_ref_Parameter__reverse(struct ArrayIter_ref_Parameter self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_Parameter ArrayIter_ref_Parameter__skip(struct ArrayIter_ref_Parameter self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_Parameter__next(struct ArrayIter_ref_Parameter* self);

#line 43 "src/std/Array.pv"
struct Parameter* ArrayIter_ref_Parameter__value(struct ArrayIter_ref_Parameter* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Parameter ArrayIter_ref_Parameter__enumerate(struct ArrayIter_ref_Parameter self);

#endif
