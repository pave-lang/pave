#ifndef PAVE_SLICE_STR
#define PAVE_SLICE_STR

#include <std/str.h>
#include <std/Iter_ref_str.h>
struct slice_str { struct str* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_str slice_str__iter(struct slice_str self);

#endif
