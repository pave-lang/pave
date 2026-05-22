#ifndef PAVE_SLICE_REF_STRUCT
#define PAVE_SLICE_REF_STRUCT

#include <std/Iter_ref_ref_Struct.h>
struct Struct;
struct slice_ref_Struct { struct Struct** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Struct slice_ref_Struct__iter(struct slice_ref_Struct self);

#endif
