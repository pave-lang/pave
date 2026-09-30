#ifndef PAVE_HASH_MAP_STR_I64
#define PAVE_HASH_MAP_STR_I64

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_i64;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_i64 {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_i64** buckets;
    struct HashMapBucket_str_i64* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/HashMapIter_str_i64.h>
#include <std/trait_Map_str_i64.h>
struct str;
struct HashMapBucket_str_i64;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_i64 HashMap_str_i64__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_i64 HashMap_str_i64__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_i64__resize(struct HashMap_str_i64* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
int64_t* HashMap_str_i64__find(struct HashMap_str_i64* self, struct str* key);

#line 78 "src/std/HashMap.pv"
int64_t* HashMap_str_i64__insert(struct HashMap_str_i64* self, struct str key, int64_t value);

#line 112 "src/std/HashMap.pv"
bool HashMap_str_i64__remove(struct HashMap_str_i64* self, struct str* key);

#line 136 "src/std/HashMap.pv"
void HashMap_str_i64__release(struct HashMap_str_i64* self);

#line 145 "src/std/HashMap.pv"
void HashMap_str_i64__fill_buckets(struct HashMap_str_i64* self);

#line 166 "src/std/HashMap.pv"
struct HashMap_str_i64 HashMap_str_i64__clone(struct HashMap_str_i64* self, struct trait_Allocator allocator);

#line 180 "src/std/HashMap.pv"
struct HashMapIter_str_i64 HashMap_str_i64__iter(struct HashMap_str_i64* self);

#line 187 "src/std/HashMap.pv"
void HashMap_str_i64__clear(struct HashMap_str_i64* self);

#line 196 "src/std/HashMap.pv"
struct HashMapBucket_str_i64* HashMap_str_i64__Index__index(void* __self);

#line 202 "src/std/HashMap.pv"
int64_t* HashMap_str_i64__Map_str_i64__find(void* __self, struct str* key);

#line 219 "src/std/HashMap.pv"
int64_t* HashMap_str_i64__Map_str_i64__insert(void* __self, struct str key, int64_t value);

#line 253 "src/std/HashMap.pv"
bool HashMap_str_i64__Map_str_i64__remove(void* __self, struct str* key);

extern struct trait_Map_str_i64VTable HASH_MAP_STR_I64__VTABLE__MAP;

#endif
