#ifndef PAVE_SLICE_DESTRUCTURE_BINDING
#define PAVE_SLICE_DESTRUCTURE_BINDING

#include <analyzer/statement/DestructureBinding.h>
#include <std/Iter_ref_DestructureBinding.h>
struct slice_DestructureBinding { struct DestructureBinding* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_DestructureBinding slice_DestructureBinding__iter(struct slice_DestructureBinding self);

#endif
