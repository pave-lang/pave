#ifndef PAVE_HASH_MAP_STR_ARRAY_SIGNATURE_INFO
#define PAVE_HASH_MAP_STR_ARRAY_SIGNATURE_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_SignatureInfo;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_SignatureInfo** buckets;
    struct HashMapBucket_str_Array_SignatureInfo* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Array_SignatureInfo.h>
#include <std/str.h>
#include <std/Array_SignatureInfo.h>
#include <std/HashMapIter_str_Array_SignatureInfo.h>
struct HashMap_str_Array_SignatureInfo;
struct str;
struct Array_SignatureInfo;
struct HashMapBucket_str_Array_SignatureInfo;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__resize(struct HashMap_str_Array_SignatureInfo* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__find(struct HashMap_str_Array_SignatureInfo* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__insert(struct HashMap_str_Array_SignatureInfo* self, struct str key, struct Array_SignatureInfo value);

#line 107 "src/std/HashMap.pv"
bool HashMap_str_Array_SignatureInfo__remove(struct HashMap_str_Array_SignatureInfo* self, struct str* key);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__release(struct HashMap_str_Array_SignatureInfo* self);

#line 140 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__fill_buckets(struct HashMap_str_Array_SignatureInfo* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__clone(struct HashMap_str_Array_SignatureInfo* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__iter(struct HashMap_str_Array_SignatureInfo* self);

#line 182 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__clear(struct HashMap_str_Array_SignatureInfo* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_SignatureInfo* HashMap_str_Array_SignatureInfo__Index__index(void* __self);

#line 197 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__find(void* __self, struct str* key);

#line 214 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__insert(void* __self, struct str key, struct Array_SignatureInfo value);

#line 244 "src/std/HashMap.pv"
bool HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_SignatureInfoVTable HASH_MAP_STR_ARRAY_SIGNATURE_INFO__VTABLE__MAP;

#endif
