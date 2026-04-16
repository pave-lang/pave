#ifndef PAVE_SLICE_IMPL
#define PAVE_SLICE_IMPL

#include <analyzer/Impl.h>
#include <std/Iter_ref_Impl.h>
struct slice_Impl { struct Impl* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Impl slice_Impl__iter(struct slice_Impl self);

#endif
