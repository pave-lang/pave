#ifndef PAVE_HASH_MAP_BUCKET_STR_TRAIT
#define PAVE_HASH_MAP_BUCKET_STR_TRAIT

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Trait;
#include <std/str.h>
#include <analyzer/types/Trait.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Trait {
    struct str key;
    struct Trait value;
    struct HashMapBucket_str_Trait* next;
};

#endif
