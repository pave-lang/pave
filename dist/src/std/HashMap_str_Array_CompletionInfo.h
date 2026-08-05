#ifndef PAVE_HASH_MAP_STR_ARRAY_COMPLETION_INFO
#define PAVE_HASH_MAP_STR_ARRAY_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_CompletionInfo;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_Array_CompletionInfo {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_CompletionInfo** buckets;
    struct HashMapBucket_str_Array_CompletionInfo* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/Array_CompletionInfo.h>
#include <std/HashMapIter_str_Array_CompletionInfo.h>
#include <std/trait_Map_str_Array_CompletionInfo.h>
struct str;
struct Array_CompletionInfo;
struct HashMapBucket_str_Array_CompletionInfo;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Array_CompletionInfo HashMap_str_Array_CompletionInfo__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Array_CompletionInfo HashMap_str_Array_CompletionInfo__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Array_CompletionInfo__resize(struct HashMap_str_Array_CompletionInfo* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Array_CompletionInfo* HashMap_str_Array_CompletionInfo__find(struct HashMap_str_Array_CompletionInfo* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Array_CompletionInfo* HashMap_str_Array_CompletionInfo__insert(struct HashMap_str_Array_CompletionInfo* self, struct str key, struct Array_CompletionInfo value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_Array_CompletionInfo__remove(struct HashMap_str_Array_CompletionInfo* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_Array_CompletionInfo__release(struct HashMap_str_Array_CompletionInfo* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_Array_CompletionInfo__fill_buckets(struct HashMap_str_Array_CompletionInfo* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_Array_CompletionInfo HashMap_str_Array_CompletionInfo__clone(struct HashMap_str_Array_CompletionInfo* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_Array_CompletionInfo HashMap_str_Array_CompletionInfo__iter(struct HashMap_str_Array_CompletionInfo* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_Array_CompletionInfo__clear(struct HashMap_str_Array_CompletionInfo* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_CompletionInfo* HashMap_str_Array_CompletionInfo__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Array_CompletionInfo* HashMap_str_Array_CompletionInfo__Map_str_Array_CompletionInfo__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Array_CompletionInfo* HashMap_str_Array_CompletionInfo__Map_str_Array_CompletionInfo__insert(void* __self, struct str key, struct Array_CompletionInfo value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_Array_CompletionInfo__Map_str_Array_CompletionInfo__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_CompletionInfoVTable HASH_MAP_STR_ARRAY_COMPLETION_INFO__VTABLE__MAP;

#endif
