#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_FUNCTION_USAGE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeFunctionUsage;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeFunctionUsage {
    struct HashMapBucket_usize_TypeFunctionUsage* iter;
    struct HashMapBucket_usize_TypeFunctionUsage* end;
};

struct HashMapIter_usize_TypeFunctionUsage;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeFunctionUsage__next(struct HashMapIter_usize_TypeFunctionUsage* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeFunctionUsage* HashMapIter_usize_TypeFunctionUsage__value(struct HashMapIter_usize_TypeFunctionUsage* self);

#endif
