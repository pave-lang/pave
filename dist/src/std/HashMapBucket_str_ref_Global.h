#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_GLOBAL
#define PAVE_HASH_MAP_BUCKET_STR_REF_GLOBAL

#include <std/str.h>
struct Global;
struct HashMapBucket_str_ref_Global;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Global {
    struct str key;
    struct Global* value;
    struct HashMapBucket_str_ref_Global* next;
};

#endif
