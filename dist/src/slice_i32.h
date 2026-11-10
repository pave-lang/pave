#ifndef PAVE_SLICE_I32
#define PAVE_SLICE_I32

#include <stdint.h>

#include <std/Iter_ref_i32.h>
struct slice_i32 { int32_t* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_i32 slice_i32__iter(struct slice_i32 self);

#endif
