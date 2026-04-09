#ifndef PAVE_SLICE_TYPE
#define PAVE_SLICE_TYPE

#include <stdint.h>

struct Type;

struct slice_Type { struct Type* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Type slice_Type__iter(struct slice_Type self);

#endif
