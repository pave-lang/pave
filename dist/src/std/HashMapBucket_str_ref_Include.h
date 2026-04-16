#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_INCLUDE
#define PAVE_HASH_MAP_BUCKET_STR_REF_INCLUDE

#include <stdio.h>
#include <string.h>

#include <std/str.h>
struct Include;
struct HashMapBucket_str_ref_Include;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Include {
    struct str key;
    struct Include* value;
    struct HashMapBucket_str_ref_Include* next;
};

#endif
