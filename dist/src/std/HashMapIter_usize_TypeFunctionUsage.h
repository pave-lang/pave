#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_usize_TypeFunctionUsage;
struct TypeFunctionUsage;

#include <stdio.h>
#include <string.h>

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeFunctionUsage {
    struct HashMapBucket_usize_TypeFunctionUsage* iter;
    struct HashMapBucket_usize_TypeFunctionUsage* end;
};

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeFunctionUsage__next(struct HashMapIter_usize_TypeFunctionUsage* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeFunctionUsage* HashMapIter_usize_TypeFunctionUsage__value(struct HashMapIter_usize_TypeFunctionUsage* self);

#endif
