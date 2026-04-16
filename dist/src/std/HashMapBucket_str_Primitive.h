#ifndef PAVE_HASH_MAP_BUCKET_STR_PRIMITIVE
#define PAVE_HASH_MAP_BUCKET_STR_PRIMITIVE

#include <std/str.h>
#include <analyzer/types/Primitive.h>
struct HashMapBucket_str_Primitive;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Primitive {
    struct str key;
    struct Primitive value;
    struct HashMapBucket_str_Primitive* next;
};

#endif
