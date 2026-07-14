#ifndef PAVE_SLICE_REF_SCOPE
#define PAVE_SLICE_REF_SCOPE

#include <std/Iter_ref_ref_Scope.h>
struct Scope;
struct slice_ref_Scope { struct Scope** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Scope slice_ref_Scope__iter(struct slice_ref_Scope self);

#endif
