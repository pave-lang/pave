#ifndef PAVE_ITER_ENUMERATE_REF_REF_TRAIT_FORMAT
#define PAVE_ITER_ENUMERATE_REF_REF_TRAIT_FORMAT

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_ref_trait_Format.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_trait_Format {
    uintptr_t index;
    struct Iter_ref_ref_trait_Format iter;
};

#include <tuple_usize_ref_ref_trait_Format.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_trait_Format__next(struct IterEnumerate_ref_ref_trait_Format* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_trait_Format IterEnumerate_ref_ref_trait_Format__value(struct IterEnumerate_ref_ref_trait_Format* self);

#endif
