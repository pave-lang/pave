#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_MEMBER_COMPLETION_INFO
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_MEMBER_COMPLETION_INFO

#include <std/str.h>
#include <std/Array_MemberCompletionInfo.h>

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_MemberCompletionInfo {
    struct str key;
    struct Array_MemberCompletionInfo value;
    struct HashMapBucket_str_Array_MemberCompletionInfo* next;
};

#endif
