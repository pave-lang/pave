#ifndef PAVE_SLICE_REF_ENUM
#define PAVE_SLICE_REF_ENUM

#include <std/Iter_ref_ref_Enum.h>
struct Enum;
struct slice_ref_Enum { struct Enum** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Enum slice_ref_Enum__iter(struct slice_ref_Enum self);

#endif
