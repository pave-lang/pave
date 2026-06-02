#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_COMPLETION_INFO
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_COMPLETION_INFO

#include <std/str.h>
#include <std/Array_CompletionInfo.h>
struct HashMapBucket_str_Array_CompletionInfo;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_CompletionInfo {
    struct str key;
    struct Array_CompletionInfo value;
    struct HashMapBucket_str_Array_CompletionInfo* next;
};

#endif
