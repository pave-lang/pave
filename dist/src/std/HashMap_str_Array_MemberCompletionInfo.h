#ifndef PAVE_HASH_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO
#define PAVE_HASH_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_MemberCompletionInfo;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_MemberCompletionInfo** buckets;
    struct HashMapBucket_str_Array_MemberCompletionInfo* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/Array_MemberCompletionInfo.h>
#include <std/HashMapIter_str_Array_MemberCompletionInfo.h>
#include <std/trait_Map_str_Array_MemberCompletionInfo.h>
struct str;
struct Array_MemberCompletionInfo;
struct HashMapBucket_str_Array_MemberCompletionInfo;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__resize(struct HashMap_str_Array_MemberCompletionInfo* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__find(struct HashMap_str_Array_MemberCompletionInfo* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__insert(struct HashMap_str_Array_MemberCompletionInfo* self, struct str key, struct Array_MemberCompletionInfo value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_Array_MemberCompletionInfo__remove(struct HashMap_str_Array_MemberCompletionInfo* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__release(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__fill_buckets(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__clone(struct HashMap_str_Array_MemberCompletionInfo* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_Array_MemberCompletionInfo HashMap_str_Array_MemberCompletionInfo__iter(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_Array_MemberCompletionInfo__clear(struct HashMap_str_Array_MemberCompletionInfo* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__Map_str_Array_MemberCompletionInfo__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Array_MemberCompletionInfo* HashMap_str_Array_MemberCompletionInfo__Map_str_Array_MemberCompletionInfo__insert(void* __self, struct str key, struct Array_MemberCompletionInfo value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_Array_MemberCompletionInfo__Map_str_Array_MemberCompletionInfo__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_MemberCompletionInfoVTable HASH_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO__VTABLE__MAP;

#endif
