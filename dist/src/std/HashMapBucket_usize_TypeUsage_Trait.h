#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_TRAIT
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_TRAIT

#include <stdint.h>
#include <compiler/TypeUsage_Trait.h>
#include <analyzer/Trait.h>

struct HashMapBucket_usize_TypeUsage_Trait;
struct TypeUsage_Trait;
struct Trait;

#include <stdio.h>
#include <string.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Trait {
    uintptr_t key;
    struct TypeUsage_Trait value;
    struct HashMapBucket_usize_TypeUsage_Trait* next;
};

#endif
