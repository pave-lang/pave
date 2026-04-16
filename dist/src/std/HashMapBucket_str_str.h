#ifndef PAVE_HASH_MAP_BUCKET_STR_STR
#define PAVE_HASH_MAP_BUCKET_STR_STR

#include <std/str.h>
struct HashMapBucket_str_str;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_str {
    struct str key;
    struct str value;
    struct HashMapBucket_str_str* next;
};

#endif
