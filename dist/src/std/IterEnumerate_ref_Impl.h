#ifndef PAVE_ITER_ENUMERATE_REF_IMPL
#define PAVE_ITER_ENUMERATE_REF_IMPL

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_Impl.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Impl {
    uintptr_t index;
    struct Iter_ref_Impl iter;
};

#include <tuple_usize_ref_Impl.h>
struct IterEnumerate_ref_Impl;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Impl__next(struct IterEnumerate_ref_Impl* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Impl IterEnumerate_ref_Impl__value(struct IterEnumerate_ref_Impl* self);

#endif
