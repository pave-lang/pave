#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_TRAIT
#define PAVE_HASH_MAP_BUCKET_STR_REF_TRAIT

#include <stdio.h>
#include <string.h>

#include <std/str.h>
struct Trait;
struct HashMapBucket_str_ref_Trait;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Trait {
    struct str key;
    struct Trait* value;
    struct HashMapBucket_str_ref_Trait* next;
};

#endif
