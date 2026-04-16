#ifndef PAVE_HASH_MAP_BUCKET_STR_TUPLE_REF_TRAIT_REF_TYPE
#define PAVE_HASH_MAP_BUCKET_STR_TUPLE_REF_TRAIT_REF_TYPE

#include <stdio.h>
#include <string.h>

#include <std/str.h>
#include <tuple_ref_Trait_ref_Type.h>
struct HashMapBucket_str_tuple_ref_Trait_ref_Type;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_tuple_ref_Trait_ref_Type {
    struct str key;
    struct tuple_ref_Trait_ref_Type value;
    struct HashMapBucket_str_tuple_ref_Trait_ref_Type* next;
};

#endif
