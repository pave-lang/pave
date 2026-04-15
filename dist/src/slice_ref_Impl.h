#ifndef PAVE_SLICE_REF_IMPL
#define PAVE_SLICE_REF_IMPL

struct Impl;
#include <std/Iter_ref_ref_Impl.h>
struct slice_ref_Impl { struct Impl** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Impl slice_ref_Impl__iter(struct slice_ref_Impl self);

#endif
