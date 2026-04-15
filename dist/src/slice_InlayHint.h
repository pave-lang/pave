#ifndef PAVE_SLICE_INLAY_HINT
#define PAVE_SLICE_INLAY_HINT

#include <analyzer/InlayHint.h>
#include <std/Iter_ref_InlayHint.h>
struct slice_InlayHint { struct InlayHint* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_InlayHint slice_InlayHint__iter(struct slice_InlayHint self);

#endif
