#ifndef PAVE_SLICE_STRING
#define PAVE_SLICE_STRING

#include <std/String.h>
#include <std/Iter_ref_String.h>
struct slice_String { struct String* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_String slice_String__iter(struct slice_String self);

#endif
