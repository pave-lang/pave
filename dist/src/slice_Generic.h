#ifndef PAVE_SLICE_GENERIC
#define PAVE_SLICE_GENERIC

#include <stdint.h>

struct Generic;

struct slice_Generic { struct Generic* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Generic slice_Generic__iter(struct slice_Generic self);

#endif
