#ifndef PAVE_ITER_ENUMERATE_REF_TYPE_IMPL
#define PAVE_ITER_ENUMERATE_REF_TYPE_IMPL

#include <stdint.h>
#include <std/Iter_ref_TypeImpl.h>
#include <stdbool.h>

struct TypeImpl;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_TypeImpl {
    uintptr_t index;
    struct Iter_ref_TypeImpl iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_TypeImpl__next(struct IterEnumerate_ref_TypeImpl* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_TypeImpl IterEnumerate_ref_TypeImpl__value(struct IterEnumerate_ref_TypeImpl* self);

#endif
