#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_REF_ENUM
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_REF_ENUM

#include <std/str.h>
#include <std/Array_ref_Enum.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_ref_Enum {
    struct str key;
    struct Array_ref_Enum value;
    struct HashMapBucket_str_Array_ref_Enum* next;
};

#endif
