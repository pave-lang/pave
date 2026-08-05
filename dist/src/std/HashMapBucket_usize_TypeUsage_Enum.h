#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_ENUM
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_ENUM

#include <stdint.h>

#include <compiler/TypeUsage_Enum.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Enum {
    uintptr_t key;
    struct TypeUsage_Enum value;
    struct HashMapBucket_usize_TypeUsage_Enum* next;
};

#endif
