#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_REF_STRUCT
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_REF_STRUCT

#include <std/str.h>
#include <std/Array_ref_Struct.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_ref_Struct {
    struct str key;
    struct Array_ref_Struct value;
    struct HashMapBucket_str_Array_ref_Struct* next;
};

#endif
