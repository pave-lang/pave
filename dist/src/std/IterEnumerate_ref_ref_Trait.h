#ifndef PAVE_ITER_ENUMERATE_REF_REF_TRAIT
#define PAVE_ITER_ENUMERATE_REF_REF_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_ref_Trait.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Trait {
    uintptr_t index;
    struct Iter_ref_ref_Trait iter;
};

#include <tuple_usize_ref_ref_Trait.h>
struct IterEnumerate_ref_ref_Trait;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Trait__next(struct IterEnumerate_ref_ref_Trait* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Trait IterEnumerate_ref_ref_Trait__value(struct IterEnumerate_ref_ref_Trait* self);

#endif
