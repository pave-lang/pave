#ifndef PAVE_SLICE_NULL_NARROWING
#define PAVE_SLICE_NULL_NARROWING

#include <analyzer/expression/NullNarrowing.h>
#include <std/Iter_ref_NullNarrowing.h>
struct slice_NullNarrowing { struct NullNarrowing* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_NullNarrowing slice_NullNarrowing__iter(struct slice_NullNarrowing self);

#endif
