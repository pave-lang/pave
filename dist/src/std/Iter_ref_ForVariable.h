#ifndef PAVE_ITER_REF_FOR_VARIABLE
#define PAVE_ITER_REF_FOR_VARIABLE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct ForVariable;

#line 4 "src/std/Array.pv"
struct Iter_ref_ForVariable {
    intptr_t step;
    struct ForVariable* iter;
    struct ForVariable* start;
    struct ForVariable* end;
};

#include <std/Iter_ref_ForVariable.h>
#include <std/IterEnumerate_ref_ForVariable.h>
struct ForVariable;
struct Iter_ref_ForVariable;

#line 12 "src/std/Array.pv"
struct Iter_ref_ForVariable Iter_ref_ForVariable__new(struct ForVariable* start, struct ForVariable* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ForVariable Iter_ref_ForVariable__reverse(struct Iter_ref_ForVariable self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ForVariable Iter_ref_ForVariable__skip(struct Iter_ref_ForVariable self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ForVariable__next(struct Iter_ref_ForVariable* self);

#line 43 "src/std/Array.pv"
struct ForVariable* Iter_ref_ForVariable__value(struct Iter_ref_ForVariable* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ForVariable Iter_ref_ForVariable__enumerate(struct Iter_ref_ForVariable self);

#endif
