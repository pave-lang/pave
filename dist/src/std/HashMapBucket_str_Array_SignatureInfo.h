#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_SIGNATURE_INFO
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_SIGNATURE_INFO

#include <std/str.h>
#include <std/Array_SignatureInfo.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_SignatureInfo {
    struct str key;
    struct Array_SignatureInfo value;
    struct HashMapBucket_str_Array_SignatureInfo* next;
};

#endif
