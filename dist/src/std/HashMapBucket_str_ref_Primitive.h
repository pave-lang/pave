#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_PRIMITIVE
#define PAVE_HASH_MAP_BUCKET_STR_REF_PRIMITIVE

#include <std/str.h>
struct Primitive;

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Primitive {
    struct str key;
    struct Primitive* value;
    struct HashMapBucket_str_ref_Primitive* next;
};

#endif
