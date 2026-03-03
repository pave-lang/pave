#ifndef PAVE_SLICE_SCOPE
#define PAVE_SLICE_SCOPE

#include <stdint.h>

struct Scope;

struct slice_Scope { struct Scope* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Scope slice_Scope__iter(struct slice_Scope self);

#endif
