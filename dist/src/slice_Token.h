#ifndef PAVE_SLICE_TOKEN
#define PAVE_SLICE_TOKEN

#include <analyzer/Token.h>
#include <std/Iter_ref_Token.h>
struct slice_Token { struct Token* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Token slice_Token__iter(struct slice_Token self);

#endif
