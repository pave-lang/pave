#ifndef PAVE_SLICE_SCOPE
#define PAVE_SLICE_SCOPE

#include <analyzer/Scope.h>
#include <std/Iter_ref_Scope.h>
struct slice_Scope { struct Scope* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Scope slice_Scope__iter(struct slice_Scope self);

#endif
