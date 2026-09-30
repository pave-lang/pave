#ifndef PAVE_SLICE_U32
#define PAVE_SLICE_U32

#include <stdint.h>

#include <std/Iter_ref_u32.h>
struct slice_u32 { uint32_t* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_u32 slice_u32__iter(struct slice_u32 self);

#endif
