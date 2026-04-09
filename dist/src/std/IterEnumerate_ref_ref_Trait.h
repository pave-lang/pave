#ifndef PAVE_ITER_ENUMERATE_REF_REF_TRAIT
#define PAVE_ITER_ENUMERATE_REF_REF_TRAIT

#include <stdint.h>
#include <std/Iter_ref_ref_Trait.h>
#include <stdbool.h>

struct Trait;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Trait {
    uintptr_t index;
    struct Iter_ref_ref_Trait iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Trait__next(struct IterEnumerate_ref_ref_Trait* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Trait IterEnumerate_ref_ref_Trait__value(struct IterEnumerate_ref_ref_Trait* self);

#endif
