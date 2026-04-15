#ifndef PAVE_ITER_REF_INLAY_HINT
#define PAVE_ITER_REF_INLAY_HINT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct InlayHint;

#line 4 "src/std/Array.pv"
struct Iter_ref_InlayHint {
    intptr_t step;
    struct InlayHint* iter;
    struct InlayHint* start;
    struct InlayHint* end;
};

struct InlayHint;
struct Iter_ref_InlayHint;
#include <std/Iter_ref_InlayHint.h>
#include <std/IterEnumerate_ref_InlayHint.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_InlayHint Iter_ref_InlayHint__new(struct InlayHint* start, struct InlayHint* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_InlayHint Iter_ref_InlayHint__reverse(struct Iter_ref_InlayHint self);

#line 33 "src/std/Array.pv"
struct Iter_ref_InlayHint Iter_ref_InlayHint__skip(struct Iter_ref_InlayHint self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_InlayHint__next(struct Iter_ref_InlayHint* self);

#line 43 "src/std/Array.pv"
struct InlayHint* Iter_ref_InlayHint__value(struct Iter_ref_InlayHint* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_InlayHint Iter_ref_InlayHint__enumerate(struct Iter_ref_InlayHint self);

#endif
