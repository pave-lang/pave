#ifndef PAVE_HASH_MAP_BUCKET_STR_I64
#define PAVE_HASH_MAP_BUCKET_STR_I64

#include <stdint.h>

#include <std/str.h>
struct HashMapBucket_str_i64;

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_i64 {
    struct str key;
    int64_t value;
    struct HashMapBucket_str_i64* next;
};

#endif
