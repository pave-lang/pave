#ifndef PAVE_ITER_ENUMERATE_REF_TYPE
#define PAVE_ITER_ENUMERATE_REF_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_Type.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Type {
    uintptr_t index;
    struct Iter_ref_Type iter;
};

#include <tuple_usize_ref_Type.h>
struct IterEnumerate_ref_Type;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Type__next(struct IterEnumerate_ref_Type* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Type IterEnumerate_ref_Type__value(struct IterEnumerate_ref_Type* self);

#endif
