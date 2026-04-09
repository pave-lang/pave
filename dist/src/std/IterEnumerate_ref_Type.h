#ifndef PAVE_ITER_ENUMERATE_REF_TYPE
#define PAVE_ITER_ENUMERATE_REF_TYPE

#include <stdint.h>
#include <std/Iter_ref_Type.h>
#include <stdbool.h>

struct Type;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Type {
    uintptr_t index;
    struct Iter_ref_Type iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Type__next(struct IterEnumerate_ref_Type* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Type IterEnumerate_ref_Type__value(struct IterEnumerate_ref_Type* self);

#endif
