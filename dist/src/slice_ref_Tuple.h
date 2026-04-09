#ifndef PAVE_SLICE_REF_TUPLE
#define PAVE_SLICE_REF_TUPLE

#include <stdint.h>

struct Tuple;

struct slice_ref_Tuple { struct Tuple** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Tuple slice_ref_Tuple__iter(struct slice_ref_Tuple self);

#endif
