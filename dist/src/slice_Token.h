#ifndef PAVE_SLICE_TOKEN
#define PAVE_SLICE_TOKEN

#include <stdint.h>

struct Token;

struct slice_Token { struct Token* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Token slice_Token__iter(struct slice_Token self);

#endif
