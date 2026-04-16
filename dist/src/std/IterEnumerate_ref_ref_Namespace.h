#ifndef PAVE_ITER_ENUMERATE_REF_REF_NAMESPACE
#define PAVE_ITER_ENUMERATE_REF_REF_NAMESPACE

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_ref_Namespace.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Namespace {
    uintptr_t index;
    struct Iter_ref_ref_Namespace iter;
};

#include <tuple_usize_ref_ref_Namespace.h>
struct IterEnumerate_ref_ref_Namespace;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Namespace__next(struct IterEnumerate_ref_ref_Namespace* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Namespace IterEnumerate_ref_ref_Namespace__value(struct IterEnumerate_ref_ref_Namespace* self);

#endif
