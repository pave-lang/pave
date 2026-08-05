#ifndef PAVE_ITER_ENUMERATE_REF_NULL_NARROWING
#define PAVE_ITER_ENUMERATE_REF_NULL_NARROWING

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_NullNarrowing.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_NullNarrowing {
    uintptr_t index;
    struct Iter_ref_NullNarrowing iter;
};

#include <tuple_usize_ref_NullNarrowing.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_NullNarrowing__next(struct IterEnumerate_ref_NullNarrowing* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_NullNarrowing IterEnumerate_ref_NullNarrowing__value(struct IterEnumerate_ref_NullNarrowing* self);

#endif
