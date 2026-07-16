#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_MEMBER_COMPLETION_INFO
#define PAVE_HASH_MAP_ITER_STR_ARRAY_MEMBER_COMPLETION_INFO

#include <stdbool.h>

struct HashMapBucket_str_Array_MemberCompletionInfo;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_Array_MemberCompletionInfo {
    struct HashMapBucket_str_Array_MemberCompletionInfo* iter;
    struct HashMapBucket_str_Array_MemberCompletionInfo* end;
};

struct HashMapIter_str_Array_MemberCompletionInfo;

#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_Array_MemberCompletionInfo__next(struct HashMapIter_str_Array_MemberCompletionInfo* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_Array_MemberCompletionInfo* HashMapIter_str_Array_MemberCompletionInfo__value(struct HashMapIter_str_Array_MemberCompletionInfo* self);

#endif
