#ifndef PAVE_ITER_ENUMERATE_REF_REF_STRUCT
#define PAVE_ITER_ENUMERATE_REF_REF_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_ref_Struct.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Struct {
    uintptr_t index;
    struct Iter_ref_ref_Struct iter;
};

#include <tuple_usize_ref_ref_Struct.h>
struct IterEnumerate_ref_ref_Struct;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Struct__next(struct IterEnumerate_ref_ref_Struct* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Struct IterEnumerate_ref_ref_Struct__value(struct IterEnumerate_ref_ref_Struct* self);

#endif
