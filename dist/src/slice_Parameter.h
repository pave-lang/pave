#ifndef PAVE_SLICE_PARAMETER
#define PAVE_SLICE_PARAMETER

#include <analyzer/types/Parameter.h>
#include <std/Iter_ref_Parameter.h>
struct slice_Parameter { struct Parameter* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Parameter slice_Parameter__iter(struct slice_Parameter self);

#endif
