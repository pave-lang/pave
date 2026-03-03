#ifndef PAVE_ARRAY_ITER_REF_INLAY_HINT
#define PAVE_ARRAY_ITER_REF_INLAY_HINT

#include <stdint.h>
#include <stdbool.h>

struct InlayHint;
struct IterEnumerate_ref_InlayHint;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_InlayHint {
    intptr_t step;
    struct InlayHint* iter;
    struct InlayHint* start;
    struct InlayHint* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_InlayHint ArrayIter_ref_InlayHint__new(struct InlayHint* start, struct InlayHint* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_InlayHint ArrayIter_ref_InlayHint__reverse(struct ArrayIter_ref_InlayHint self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_InlayHint ArrayIter_ref_InlayHint__skip(struct ArrayIter_ref_InlayHint self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_InlayHint__next(struct ArrayIter_ref_InlayHint* self);

#line 43 "src/std/Array.pv"
struct InlayHint* ArrayIter_ref_InlayHint__value(struct ArrayIter_ref_InlayHint* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_InlayHint ArrayIter_ref_InlayHint__enumerate(struct ArrayIter_ref_InlayHint self);

#endif
