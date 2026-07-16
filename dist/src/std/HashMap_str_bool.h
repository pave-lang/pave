#ifndef PAVE_HASH_MAP_STR_BOOL
#define PAVE_HASH_MAP_STR_BOOL

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_bool;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_bool {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_bool** buckets;
    struct HashMapBucket_str_bool* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_bool.h>
#include <std/str.h>
#include <std/HashMapIter_str_bool.h>
struct HashMap_str_bool;
struct str;
struct HashMapBucket_str_bool;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_bool__resize(struct HashMap_str_bool* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
bool* HashMap_str_bool__find(struct HashMap_str_bool* self, struct str* key);

#line 78 "src/std/HashMap.pv"
bool* HashMap_str_bool__insert(struct HashMap_str_bool* self, struct str key, bool value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_bool__remove(struct HashMap_str_bool* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_bool__release(struct HashMap_str_bool* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_bool__fill_buckets(struct HashMap_str_bool* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__clone(struct HashMap_str_bool* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_bool HashMap_str_bool__iter(struct HashMap_str_bool* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_bool__clear(struct HashMap_str_bool* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_bool* HashMap_str_bool__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
bool* HashMap_str_bool__Map_str_bool__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
bool* HashMap_str_bool__Map_str_bool__insert(void* __self, struct str key, bool value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_bool__Map_str_bool__remove(void* __self, struct str* key);

extern struct trait_Map_str_boolVTable HASH_MAP_STR_BOOL__VTABLE__MAP;

#endif
