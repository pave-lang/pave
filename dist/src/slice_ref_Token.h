#ifndef PAVE_SLICE_REF_TOKEN
#define PAVE_SLICE_REF_TOKEN

#include <stdint.h>

struct Token;

struct slice_ref_Token { struct Token** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Token slice_ref_Token__iter(struct slice_ref_Token self);

#endif
