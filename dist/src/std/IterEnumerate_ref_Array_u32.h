#ifndef PAVE_ITER_ENUMERATE_REF_ARRAY_U32
#define PAVE_ITER_ENUMERATE_REF_ARRAY_U32

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_Array_u32.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Array_u32 {
    uintptr_t index;
    struct Iter_ref_Array_u32 iter;
};

#include <tuple_usize_ref_Array_u32.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Array_u32__next(struct IterEnumerate_ref_Array_u32* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Array_u32 IterEnumerate_ref_Array_u32__value(struct IterEnumerate_ref_Array_u32* self);

#endif
