#ifndef PAVE_ITER_REF_IMPL_NODE
#define PAVE_ITER_REF_IMPL_NODE

#include <stdint.h>
#include <stdbool.h>

struct ImplNode;

#line 4 "src/std/Array.pv"
struct Iter_ref_ImplNode {
    intptr_t step;
    struct ImplNode* iter;
    struct ImplNode* start;
    struct ImplNode* end;
};

#include <std/Iter_ref_ImplNode.h>
#include <std/IterEnumerate_ref_ImplNode.h>
struct ImplNode;
struct Iter_ref_ImplNode;

#line 12 "src/std/Array.pv"
struct Iter_ref_ImplNode Iter_ref_ImplNode__new(struct ImplNode* start, struct ImplNode* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ImplNode Iter_ref_ImplNode__reverse(struct Iter_ref_ImplNode self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ImplNode Iter_ref_ImplNode__skip(struct Iter_ref_ImplNode self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ImplNode__next(struct Iter_ref_ImplNode* self);

#line 43 "src/std/Array.pv"
struct ImplNode* Iter_ref_ImplNode__value(struct Iter_ref_ImplNode* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ImplNode Iter_ref_ImplNode__enumerate(struct Iter_ref_ImplNode self);

#endif
