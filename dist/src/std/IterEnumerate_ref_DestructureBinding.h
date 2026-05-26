#ifndef PAVE_ITER_ENUMERATE_REF_DESTRUCTURE_BINDING
#define PAVE_ITER_ENUMERATE_REF_DESTRUCTURE_BINDING

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_DestructureBinding.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_DestructureBinding {
    uintptr_t index;
    struct Iter_ref_DestructureBinding iter;
};

#include <tuple_usize_ref_DestructureBinding.h>
struct IterEnumerate_ref_DestructureBinding;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_DestructureBinding__next(struct IterEnumerate_ref_DestructureBinding* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_DestructureBinding IterEnumerate_ref_DestructureBinding__value(struct IterEnumerate_ref_DestructureBinding* self);

#endif
