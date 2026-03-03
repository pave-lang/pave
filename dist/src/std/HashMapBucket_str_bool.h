#ifndef PAVE_HASH_MAP_BUCKET_STR_BOOL
#define PAVE_HASH_MAP_BUCKET_STR_BOOL

#include <std/str.h>
#include <stdbool.h>

struct HashMapBucket_str_bool;
struct str;

#include <stdio.h>
#include <string.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_bool {
    struct str key;
    bool value;
    struct HashMapBucket_str_bool* next;
};

#endif
