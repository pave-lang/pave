#ifndef PAVE_ITER_ENUMERATE_REF_IMPL
#define PAVE_ITER_ENUMERATE_REF_IMPL

#include <stdint.h>
#include <std/ArrayIter_ref_Impl.h>
#include <stdbool.h>

struct Impl;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Impl {
    uintptr_t index;
    struct ArrayIter_ref_Impl iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Impl__next(struct IterEnumerate_ref_Impl* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Impl IterEnumerate_ref_Impl__value(struct IterEnumerate_ref_Impl* self);

#endif
