#ifndef PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_SEQUENCE
#define PAVE_HASH_MAP_BUCKET_USIZE_TYPE_USAGE_SEQUENCE

#include <stdint.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeUsage_Sequence;
#include <compiler/TypeUsage_Sequence.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Sequence {
    uintptr_t key;
    struct TypeUsage_Sequence value;
    struct HashMapBucket_usize_TypeUsage_Sequence* next;
};

#endif
