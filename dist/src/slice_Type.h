#ifndef PAVE_SLICE_TYPE
#define PAVE_SLICE_TYPE

#include <analyzer/types/Type.h>
#include <std/Iter_ref_Type.h>
struct slice_Type { struct Type* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Type slice_Type__iter(struct slice_Type self);

#endif
