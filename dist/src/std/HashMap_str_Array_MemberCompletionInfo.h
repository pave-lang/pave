#ifndef PAVE_HASH_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO
#define PAVE_HASH_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_MemberCompletionInfo;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_MemberCompletionInfo** buckets;
    struct HashMapBucket_str_Array_MemberCompletionInfo* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Array_MemberCompletionInfo.h>
#include <std/str.h>
#include <std/Array_MemberCompletionInfo.h>
#include <std/HashMapIter_str_Array_MemberCompletionInfo.h>
struct HashMap_str_Array_MemberCompletionInfo;
struct str;
struct Array_MemberCompletionInfo;
struct HashMapBucket_str_Array_MemberCompletionInfo;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__resize(struct HashMap_str_Array_MemberCompletionInfo* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__find(struct HashMap_str_Array_MemberCompletionInfo* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__insert(struct HashMap_str_Array_MemberCompletionInfo* self, struct str key, struct Array_MemberCompletionInfo value);

#line 107 "src/std/HashMap.pv"
bool HashMap_str_Array_MemberCompletionInfo__remove(struct HashMap_str_Array_MemberCompletionInfo* self, struct str* key);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__release(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 140 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__fill_buckets(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__clone(struct HashMap_str_Array_MemberCompletionInfo* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__iter(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 182 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__clear(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__Index__index(void* __self);


#endif
