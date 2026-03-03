#ifndef PAVE_SLICE_INLAY_HINT
#define PAVE_SLICE_INLAY_HINT

#include <stdint.h>

struct InlayHint;

struct slice_InlayHint { struct InlayHint* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_InlayHint slice_InlayHint__iter(struct slice_InlayHint self);

#endif
