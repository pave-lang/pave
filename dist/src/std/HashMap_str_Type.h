#ifndef PAVE_HASH_MAP_STR_TYPE
#define PAVE_HASH_MAP_STR_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Type;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Type {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Type** buckets;
    struct HashMapBucket_str_Type* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <std/HashMapIter_str_Type.h>
struct HashMap_str_Type;
struct str;
struct Type;
struct HashMapBucket_str_Type;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Type HashMap_str_Type__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Type HashMap_str_Type__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Type__resize(struct HashMap_str_Type* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Type* HashMap_str_Type__find(struct HashMap_str_Type* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Type* HashMap_str_Type__insert(struct HashMap_str_Type* self, struct str key, struct Type value);

#line 107 "src/std/HashMap.pv"
bool HashMap_str_Type__remove(struct HashMap_str_Type* self, struct str* key);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Type__release(struct HashMap_str_Type* self);

#line 140 "src/std/HashMap.pv"
void HashMap_str_Type__fill_buckets(struct HashMap_str_Type* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_str_Type HashMap_str_Type__clone(struct HashMap_str_Type* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_Type HashMap_str_Type__iter(struct HashMap_str_Type* self);

#line 182 "src/std/HashMap.pv"
void HashMap_str_Type__clear(struct HashMap_str_Type* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_Type* HashMap_str_Type__Index__index(void* __self);

#line 197 "src/std/HashMap.pv"
struct Type* HashMap_str_Type__Map_str_Type__find(void* __self, struct str* key);

#line 214 "src/std/HashMap.pv"
struct Type* HashMap_str_Type__Map_str_Type__insert(void* __self, struct str key, struct Type value);

#line 244 "src/std/HashMap.pv"
bool HashMap_str_Type__Map_str_Type__remove(void* __self, struct str* key);

extern struct trait_Map_str_TypeVTable HASH_MAP_STR_TYPE__VTABLE__MAP;

#endif
