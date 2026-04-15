#ifndef PAVE_ITER_ENUMERATE_REF_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_ITER_ENUMERATE_REF_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_HashMap_usize_TypeFunctionUsage.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage {
    uintptr_t index;
    struct Iter_ref_HashMap_usize_TypeFunctionUsage iter;
};

struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage;
#include <tuple_usize_ref_HashMap_usize_TypeFunctionUsage.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_HashMap_usize_TypeFunctionUsage__next(struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_HashMap_usize_TypeFunctionUsage IterEnumerate_ref_HashMap_usize_TypeFunctionUsage__value(struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage* self);

#endif
