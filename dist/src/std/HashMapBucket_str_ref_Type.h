#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_TYPE
#define PAVE_HASH_MAP_BUCKET_STR_REF_TYPE

#include <stdio.h>
#include <string.h>

struct Type;
struct HashMapBucket_str_ref_Type;
#include <std/str.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Type {
    struct str key;
    struct Type* value;
    struct HashMapBucket_str_ref_Type* next;
};

#endif
