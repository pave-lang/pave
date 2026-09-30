#ifndef PAVE_SLICE_ARRAY_U32
#define PAVE_SLICE_ARRAY_U32

#include <std/Array_u32.h>
#include <std/Iter_ref_Array_u32.h>
struct slice_Array_u32 { struct Array_u32* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Array_u32 slice_Array_u32__iter(struct slice_Array_u32 self);

#endif
