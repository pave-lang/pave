#ifndef PAVE_HASH_MAP_BUCKET_STR_TYPE
#define PAVE_HASH_MAP_BUCKET_STR_TYPE

#include <std/str.h>
#include <analyzer/types/Type.h>
struct HashMapBucket_str_Type;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Type {
    struct str key;
    struct Type value;
    struct HashMapBucket_str_Type* next;
};

#endif
