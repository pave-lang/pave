#ifndef PAVE_ITER_ENUMERATE_REF_INLAY_HINT
#define PAVE_ITER_ENUMERATE_REF_INLAY_HINT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_InlayHint.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_InlayHint {
    uintptr_t index;
    struct Iter_ref_InlayHint iter;
};

#include <tuple_usize_ref_InlayHint.h>
struct IterEnumerate_ref_InlayHint;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_InlayHint__next(struct IterEnumerate_ref_InlayHint* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_InlayHint IterEnumerate_ref_InlayHint__value(struct IterEnumerate_ref_InlayHint* self);

#endif
