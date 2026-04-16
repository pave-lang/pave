#ifndef PAVE_HASH_MAP_BUCKET_STR_TRAIT
#define PAVE_HASH_MAP_BUCKET_STR_TRAIT

#include <std/str.h>
#include <analyzer/types/Trait.h>
struct HashMapBucket_str_Trait;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Trait {
    struct str key;
    struct Trait value;
    struct HashMapBucket_str_Trait* next;
};

#endif
