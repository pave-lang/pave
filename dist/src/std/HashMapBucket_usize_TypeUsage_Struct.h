#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_STRUCT
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_STRUCT

#include <stdint.h>

#include <compiler/TypeUsage_Struct.h>
struct HashMapBucket_usize_TypeUsage_Struct;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Struct {
    uintptr_t key;
    struct TypeUsage_Struct value;
    struct HashMapBucket_usize_TypeUsage_Struct* next;
};

#endif
