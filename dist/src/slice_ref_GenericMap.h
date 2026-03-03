#ifndef PAVE_SLICE_REF_GENERIC_MAP
#define PAVE_SLICE_REF_GENERIC_MAP

#include <stdint.h>

struct GenericMap;

struct slice_ref_GenericMap { struct GenericMap** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_GenericMap slice_ref_GenericMap__iter(struct slice_ref_GenericMap self);

#endif
