#ifndef PAVE_SLICE_TYPE_IMPL
#define PAVE_SLICE_TYPE_IMPL

#include <analyzer/types/TypeImpl.h>
#include <std/Iter_ref_TypeImpl.h>
struct slice_TypeImpl { struct TypeImpl* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_TypeImpl slice_TypeImpl__iter(struct slice_TypeImpl self);

#endif
