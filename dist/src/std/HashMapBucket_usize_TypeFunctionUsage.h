#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>

#include <compiler/TypeFunctionUsage.h>
struct HashMapBucket_usize_TypeFunctionUsage;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeFunctionUsage {
    uintptr_t key;
    struct TypeFunctionUsage value;
    struct HashMapBucket_usize_TypeFunctionUsage* next;
};

#endif
