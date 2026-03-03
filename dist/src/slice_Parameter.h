#ifndef PAVE_SLICE_PARAMETER
#define PAVE_SLICE_PARAMETER

#include <stdint.h>

struct Parameter;

struct slice_Parameter { struct Parameter* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Parameter slice_Parameter__iter(struct slice_Parameter self);

#endif
