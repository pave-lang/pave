#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_PRIMITIVE
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_PRIMITIVE

#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <compiler/TypeUsage_Primitive.h>
struct HashMapBucket_usize_TypeUsage_Primitive;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Primitive {
    uintptr_t key;
    struct TypeUsage_Primitive value;
    struct HashMapBucket_usize_TypeUsage_Primitive* next;
};

#endif
