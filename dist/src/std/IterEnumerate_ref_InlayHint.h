#ifndef PAVE_ITER_ENUMERATE_REF_INLAY_HINT
#define PAVE_ITER_ENUMERATE_REF_INLAY_HINT

#include <stdint.h>
#include <std/ArrayIter_ref_InlayHint.h>
#include <stdbool.h>

struct InlayHint;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_InlayHint {
    uintptr_t index;
    struct ArrayIter_ref_InlayHint iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_InlayHint__next(struct IterEnumerate_ref_InlayHint* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_InlayHint IterEnumerate_ref_InlayHint__value(struct IterEnumerate_ref_InlayHint* self);

#endif
