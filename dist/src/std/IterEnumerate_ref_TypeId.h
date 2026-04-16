#ifndef PAVE_ITER_ENUMERATE_REF_TYPE_ID
#define PAVE_ITER_ENUMERATE_REF_TYPE_ID

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_TypeId.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_TypeId {
    uintptr_t index;
    struct Iter_ref_TypeId iter;
};

#include <tuple_usize_ref_TypeId.h>
struct IterEnumerate_ref_TypeId;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_TypeId__next(struct IterEnumerate_ref_TypeId* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_TypeId IterEnumerate_ref_TypeId__value(struct IterEnumerate_ref_TypeId* self);

#endif
