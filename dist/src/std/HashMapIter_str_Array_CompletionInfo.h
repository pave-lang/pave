#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_COMPLETION_INFO
#define PAVE_HASH_MAP_ITER_STR_ARRAY_COMPLETION_INFO

#include <stdbool.h>

struct HashMapBucket_str_Array_CompletionInfo;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_Array_CompletionInfo {
    struct HashMapBucket_str_Array_CompletionInfo* iter;
    struct HashMapBucket_str_Array_CompletionInfo* end;
};

struct HashMapIter_str_Array_CompletionInfo;

#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_Array_CompletionInfo__next(struct HashMapIter_str_Array_CompletionInfo* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_Array_CompletionInfo* HashMapIter_str_Array_CompletionInfo__value(struct HashMapIter_str_Array_CompletionInfo* self);

#endif
