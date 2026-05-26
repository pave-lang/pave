#ifndef PAVE_ITER_REF_DESTRUCTURE_BINDING
#define PAVE_ITER_REF_DESTRUCTURE_BINDING

#include <stdint.h>
#include <stdbool.h>

struct DestructureBinding;

#line 4 "src/std/Array.pv"
struct Iter_ref_DestructureBinding {
    intptr_t step;
    struct DestructureBinding* iter;
    struct DestructureBinding* start;
    struct DestructureBinding* end;
};

#include <std/Iter_ref_DestructureBinding.h>
#include <std/IterEnumerate_ref_DestructureBinding.h>
struct DestructureBinding;
struct Iter_ref_DestructureBinding;

#line 12 "src/std/Array.pv"
struct Iter_ref_DestructureBinding Iter_ref_DestructureBinding__new(struct DestructureBinding* start, struct DestructureBinding* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_DestructureBinding Iter_ref_DestructureBinding__reverse(struct Iter_ref_DestructureBinding self);

#line 33 "src/std/Array.pv"
struct Iter_ref_DestructureBinding Iter_ref_DestructureBinding__skip(struct Iter_ref_DestructureBinding self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_DestructureBinding__next(struct Iter_ref_DestructureBinding* self);

#line 43 "src/std/Array.pv"
struct DestructureBinding* Iter_ref_DestructureBinding__value(struct Iter_ref_DestructureBinding* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_DestructureBinding Iter_ref_DestructureBinding__enumerate(struct Iter_ref_DestructureBinding self);

#endif
