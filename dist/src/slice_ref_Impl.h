#ifndef PAVE_SLICE_REF_IMPL
#define PAVE_SLICE_REF_IMPL

#include <stdint.h>

struct Impl;

struct slice_ref_Impl { struct Impl** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Impl slice_ref_Impl__iter(struct slice_ref_Impl self);

#endif
