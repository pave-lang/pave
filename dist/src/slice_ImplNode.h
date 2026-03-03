#ifndef PAVE_SLICE_IMPL_NODE
#define PAVE_SLICE_IMPL_NODE

#include <stdint.h>

struct ImplNode;

struct slice_ImplNode { struct ImplNode* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ImplNode slice_ImplNode__iter(struct slice_ImplNode self);

#endif
