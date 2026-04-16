#ifndef PAVE_ITER_ENUMERATE_REF_GENERIC
#define PAVE_ITER_ENUMERATE_REF_GENERIC

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_Generic.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Generic {
    uintptr_t index;
    struct Iter_ref_Generic iter;
};

#include <tuple_usize_ref_Generic.h>
struct IterEnumerate_ref_Generic;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Generic__next(struct IterEnumerate_ref_Generic* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Generic IterEnumerate_ref_Generic__value(struct IterEnumerate_ref_Generic* self);

#endif
