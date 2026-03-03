#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_ENUM
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_ENUM

#include <stdint.h>
#include <compiler/TypeUsage_Enum.h>
#include <analyzer/Enum.h>

struct HashMapBucket_usize_TypeUsage_Enum;
struct TypeUsage_Enum;
struct Enum;

#include <stdio.h>
#include <string.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Enum {
    uintptr_t key;
    struct TypeUsage_Enum value;
    struct HashMapBucket_usize_TypeUsage_Enum* next;
};

#endif
