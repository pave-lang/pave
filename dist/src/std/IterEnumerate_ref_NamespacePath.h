#ifndef PAVE_ITER_ENUMERATE_REF_NAMESPACE_PATH
#define PAVE_ITER_ENUMERATE_REF_NAMESPACE_PATH

#include <stdint.h>
#include <std/ArrayIter_ref_NamespacePath.h>
#include <stdbool.h>

struct NamespacePath;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_NamespacePath {
    uintptr_t index;
    struct ArrayIter_ref_NamespacePath iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_NamespacePath__next(struct IterEnumerate_ref_NamespacePath* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_NamespacePath IterEnumerate_ref_NamespacePath__value(struct IterEnumerate_ref_NamespacePath* self);

#endif
