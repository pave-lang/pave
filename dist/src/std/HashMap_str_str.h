#ifndef PAVE_HASH_MAP_STR_STR
#define PAVE_HASH_MAP_STR_STR

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_str;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_str {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_str** buckets;
    struct HashMapBucket_str_str* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/HashMapIter_str_str.h>
#include <std/trait_Map_str_str.h>
struct str;
struct HashMapBucket_str_str;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_str HashMap_str_str__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_str HashMap_str_str__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_str__resize(struct HashMap_str_str* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct str* HashMap_str_str__find(struct HashMap_str_str* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct str* HashMap_str_str__insert(struct HashMap_str_str* self, struct str key, struct str value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_str__remove(struct HashMap_str_str* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_str__release(struct HashMap_str_str* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_str__fill_buckets(struct HashMap_str_str* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_str HashMap_str_str__clone(struct HashMap_str_str* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_str HashMap_str_str__iter(struct HashMap_str_str* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_str__clear(struct HashMap_str_str* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_str* HashMap_str_str__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct str* HashMap_str_str__Map_str_str__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct str* HashMap_str_str__Map_str_str__insert(void* __self, struct str key, struct str value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_str__Map_str_str__remove(void* __self, struct str* key);

extern struct trait_Map_str_strVTable HASH_MAP_STR_STR__VTABLE__MAP;

#endif
