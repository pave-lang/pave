#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_TYPE
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_TYPE

#include <std/str.h>
#include <std/Array_Type.h>
struct HashMapBucket_str_Array_Type;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_Type {
    struct str key;
    struct Array_Type value;
    struct HashMapBucket_str_Array_Type* next;
};

#endif
