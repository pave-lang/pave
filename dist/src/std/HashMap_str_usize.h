#ifndef PAVE_HASH_MAP_STR_USIZE
#define PAVE_HASH_MAP_STR_USIZE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_usize;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_usize {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_usize** buckets;
    struct HashMapBucket_str_usize* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <std/HashMapIter_str_usize.h>
struct HashMap_str_usize;
struct str;
struct HashMapBucket_str_usize;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_usize HashMap_str_usize__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_usize HashMap_str_usize__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_usize__resize(struct HashMap_str_usize* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
uintptr_t* HashMap_str_usize__find(struct HashMap_str_usize* self, struct str* key);

#line 78 "src/std/HashMap.pv"
uintptr_t* HashMap_str_usize__insert(struct HashMap_str_usize* self, struct str key, uintptr_t value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_usize__remove(struct HashMap_str_usize* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_usize__release(struct HashMap_str_usize* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_usize__fill_buckets(struct HashMap_str_usize* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_usize HashMap_str_usize__clone(struct HashMap_str_usize* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_usize HashMap_str_usize__iter(struct HashMap_str_usize* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_usize__clear(struct HashMap_str_usize* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_usize* HashMap_str_usize__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
uintptr_t* HashMap_str_usize__Map_str_usize__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
uintptr_t* HashMap_str_usize__Map_str_usize__insert(void* __self, struct str key, uintptr_t value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_usize__Map_str_usize__remove(void* __self, struct str* key);

extern struct trait_Map_str_usizeVTable HASH_MAP_STR_USIZE__VTABLE__MAP;

#endif
