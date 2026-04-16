#ifndef PAVE_SLICE_GENERIC
#define PAVE_SLICE_GENERIC

#include <analyzer/types/Generic.h>
#include <std/Iter_ref_Generic.h>
struct slice_Generic { struct Generic* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Generic slice_Generic__iter(struct slice_Generic self);

#endif
