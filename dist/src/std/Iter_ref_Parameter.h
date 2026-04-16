#ifndef PAVE_ITER_REF_PARAMETER
#define PAVE_ITER_REF_PARAMETER

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Parameter;

#line 4 "src/std/Array.pv"
struct Iter_ref_Parameter {
    intptr_t step;
    struct Parameter* iter;
    struct Parameter* start;
    struct Parameter* end;
};

#include <std/Iter_ref_Parameter.h>
#include <std/IterEnumerate_ref_Parameter.h>
struct Parameter;
struct Iter_ref_Parameter;

#line 12 "src/std/Array.pv"
struct Iter_ref_Parameter Iter_ref_Parameter__new(struct Parameter* start, struct Parameter* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Parameter Iter_ref_Parameter__reverse(struct Iter_ref_Parameter self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Parameter Iter_ref_Parameter__skip(struct Iter_ref_Parameter self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Parameter__next(struct Iter_ref_Parameter* self);

#line 43 "src/std/Array.pv"
struct Parameter* Iter_ref_Parameter__value(struct Iter_ref_Parameter* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Parameter Iter_ref_Parameter__enumerate(struct Iter_ref_Parameter self);

#endif
