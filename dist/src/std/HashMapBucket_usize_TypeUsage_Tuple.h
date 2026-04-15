#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_TUPLE
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_TUPLE

#include <stdint.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeUsage_Tuple;
#include <compiler/TypeUsage_Tuple.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Tuple {
    uintptr_t key;
    struct TypeUsage_Tuple value;
    struct HashMapBucket_usize_TypeUsage_Tuple* next;
};

#endif
