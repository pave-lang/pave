#ifndef PAVE_ITER_REF_DIAGNOSTIC
#define PAVE_ITER_REF_DIAGNOSTIC

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Diagnostic;

#line 4 "src/std/Array.pv"
struct Iter_ref_Diagnostic {
    intptr_t step;
    struct Diagnostic* iter;
    struct Diagnostic* start;
    struct Diagnostic* end;
};

#include <std/Iter_ref_Diagnostic.h>
#include <std/IterEnumerate_ref_Diagnostic.h>
struct Diagnostic;
struct Iter_ref_Diagnostic;

#line 12 "src/std/Array.pv"
struct Iter_ref_Diagnostic Iter_ref_Diagnostic__new(struct Diagnostic* start, struct Diagnostic* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Diagnostic Iter_ref_Diagnostic__reverse(struct Iter_ref_Diagnostic self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Diagnostic Iter_ref_Diagnostic__skip(struct Iter_ref_Diagnostic self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Diagnostic__next(struct Iter_ref_Diagnostic* self);

#line 43 "src/std/Array.pv"
struct Diagnostic* Iter_ref_Diagnostic__value(struct Iter_ref_Diagnostic* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Diagnostic Iter_ref_Diagnostic__enumerate(struct Iter_ref_Diagnostic self);

#endif
