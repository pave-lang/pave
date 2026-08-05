#ifndef PAVE_HASH_MAP_BUCKET_STR_BOOL
#define PAVE_HASH_MAP_BUCKET_STR_BOOL

#include <stdbool.h>

#include <std/str.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_bool {
    struct str key;
    bool value;
    struct HashMapBucket_str_bool* next;
};

#endif
