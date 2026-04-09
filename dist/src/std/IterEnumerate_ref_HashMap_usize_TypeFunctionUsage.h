#ifndef PAVE_ITER_ENUMERATE_REF_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_ITER_ENUMERATE_REF_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <std/Iter_ref_HashMap_usize_TypeFunctionUsage.h>
#include <stdbool.h>

struct HashMap_usize_TypeFunctionUsage;
struct TypeFunctionUsage;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage {
    uintptr_t index;
    struct Iter_ref_HashMap_usize_TypeFunctionUsage iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_HashMap_usize_TypeFunctionUsage__next(struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_HashMap_usize_TypeFunctionUsage IterEnumerate_ref_HashMap_usize_TypeFunctionUsage__value(struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage* self);

#endif
