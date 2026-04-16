#ifndef PAVE_SLICE_IMPL_NODE
#define PAVE_SLICE_IMPL_NODE

#include <analyzer/ImplNode.h>
#include <std/Iter_ref_ImplNode.h>
struct slice_ImplNode { struct ImplNode* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ImplNode slice_ImplNode__iter(struct slice_ImplNode self);

#endif
