#ifndef PAVE_HASH_MAP_BUCKET_U32_TYPE
#define PAVE_HASH_MAP_BUCKET_U32_TYPE

#include <stdint.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_u32_Type;
#include <analyzer/types/Type.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_u32_Type {
    uint32_t key;
    struct Type value;
    struct HashMapBucket_u32_Type* next;
};

#endif
