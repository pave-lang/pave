#ifndef PAVE_ITER_ENUMERATE_REF_IMPL_NODE
#define PAVE_ITER_ENUMERATE_REF_IMPL_NODE

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_ImplNode.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ImplNode {
    uintptr_t index;
    struct Iter_ref_ImplNode iter;
};

#include <tuple_usize_ref_ImplNode.h>
struct IterEnumerate_ref_ImplNode;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ImplNode__next(struct IterEnumerate_ref_ImplNode* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ImplNode IterEnumerate_ref_ImplNode__value(struct IterEnumerate_ref_ImplNode* self);

#endif
