#ifndef PAVE_SLICE_REF_NAMESPACE
#define PAVE_SLICE_REF_NAMESPACE

#include <stdint.h>

struct Namespace;

struct slice_ref_Namespace { struct Namespace** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Namespace slice_ref_Namespace__iter(struct slice_ref_Namespace self);

#endif
