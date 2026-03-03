#ifndef PAVE_ITER_ENUMERATE_REF_IMPL_NODE
#define PAVE_ITER_ENUMERATE_REF_IMPL_NODE

#include <stdint.h>
#include <std/ArrayIter_ref_ImplNode.h>
#include <stdbool.h>

struct ImplNode;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ImplNode {
    uintptr_t index;
    struct ArrayIter_ref_ImplNode iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ImplNode__next(struct IterEnumerate_ref_ImplNode* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ImplNode IterEnumerate_ref_ImplNode__value(struct IterEnumerate_ref_ImplNode* self);

#endif
