#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_REF_TRAIT
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_REF_TRAIT

#include <std/str.h>
#include <std/Array_ref_Trait.h>
struct HashMapBucket_str_Array_ref_Trait;

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_ref_Trait {
    struct str key;
    struct Array_ref_Trait value;
    struct HashMapBucket_str_Array_ref_Trait* next;
};

#endif
