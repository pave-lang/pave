#ifndef PAVE_ITER_ENUMERATE_REF_I32
#define PAVE_ITER_ENUMERATE_REF_I32

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_i32.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_i32 {
    uintptr_t index;
    struct Iter_ref_i32 iter;
};

#include <tuple_usize_ref_i32.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_i32__next(struct IterEnumerate_ref_i32* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_i32 IterEnumerate_ref_i32__value(struct IterEnumerate_ref_i32* self);

#endif
