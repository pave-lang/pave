#ifndef PAVE_SLICE_TYPE_IMPL
#define PAVE_SLICE_TYPE_IMPL

#include <stdint.h>

struct TypeImpl;

struct slice_TypeImpl { struct TypeImpl* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_TypeImpl slice_TypeImpl__iter(struct slice_TypeImpl self);

#endif
