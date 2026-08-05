#ifndef PAVE_HASH_MAP_STR_REF_TYPE
#define PAVE_HASH_MAP_STR_REF_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Type;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_ref_Type {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Type** buckets;
    struct HashMapBucket_str_ref_Type* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Type.h>
#include <std/trait_Map_str_ref_Type.h>
struct str;
struct Type;
struct HashMapBucket_str_ref_Type;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_ref_Type HashMap_str_ref_Type__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_ref_Type HashMap_str_ref_Type__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_ref_Type__resize(struct HashMap_str_ref_Type* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Type** HashMap_str_ref_Type__find(struct HashMap_str_ref_Type* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Type** HashMap_str_ref_Type__insert(struct HashMap_str_ref_Type* self, struct str key, struct Type* value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_ref_Type__remove(struct HashMap_str_ref_Type* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_ref_Type__release(struct HashMap_str_ref_Type* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_ref_Type__fill_buckets(struct HashMap_str_ref_Type* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_ref_Type HashMap_str_ref_Type__clone(struct HashMap_str_ref_Type* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Type HashMap_str_ref_Type__iter(struct HashMap_str_ref_Type* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_ref_Type__clear(struct HashMap_str_ref_Type* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Type* HashMap_str_ref_Type__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Type** HashMap_str_ref_Type__Map_str_ref_Type__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Type** HashMap_str_ref_Type__Map_str_ref_Type__insert(void* __self, struct str key, struct Type* value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_ref_Type__Map_str_ref_Type__remove(void* __self, struct str* key);

extern struct trait_Map_str_ref_TypeVTable HASH_MAP_STR_REF_TYPE__VTABLE__MAP;

#endif
