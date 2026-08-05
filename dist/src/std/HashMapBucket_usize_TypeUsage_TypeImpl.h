#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_TYPE_IMPL
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_TYPE_IMPL

#include <stdint.h>

#include <compiler/TypeUsage_TypeImpl.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_TypeImpl {
    uintptr_t key;
    struct TypeUsage_TypeImpl value;
    struct HashMapBucket_usize_TypeUsage_TypeImpl* next;
};

#endif
