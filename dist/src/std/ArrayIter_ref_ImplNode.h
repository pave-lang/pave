#ifndef PAVE_ARRAY_ITER_REF_IMPL_NODE
#define PAVE_ARRAY_ITER_REF_IMPL_NODE

#include <stdint.h>
#include <stdbool.h>

struct ImplNode;
struct IterEnumerate_ref_ImplNode;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_ImplNode {
    intptr_t step;
    struct ImplNode* iter;
    struct ImplNode* start;
    struct ImplNode* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_ImplNode ArrayIter_ref_ImplNode__new(struct ImplNode* start, struct ImplNode* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_ImplNode ArrayIter_ref_ImplNode__reverse(struct ArrayIter_ref_ImplNode self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_ImplNode ArrayIter_ref_ImplNode__skip(struct ArrayIter_ref_ImplNode self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_ImplNode__next(struct ArrayIter_ref_ImplNode* self);

#line 43 "src/std/Array.pv"
struct ImplNode* ArrayIter_ref_ImplNode__value(struct ArrayIter_ref_ImplNode* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ImplNode ArrayIter_ref_ImplNode__enumerate(struct ArrayIter_ref_ImplNode self);

#endif
