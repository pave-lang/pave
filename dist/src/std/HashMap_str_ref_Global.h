#ifndef PAVE_HASH_MAP_STR_REF_GLOBAL
#define PAVE_HASH_MAP_STR_REF_GLOBAL

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Global;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_ref_Global {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Global** buckets;
    struct HashMapBucket_str_ref_Global* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Global.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Global.h>
struct HashMap_str_ref_Global;
struct str;
struct Global;
struct HashMapBucket_str_ref_Global;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_ref_Global HashMap_str_ref_Global__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_ref_Global HashMap_str_ref_Global__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_ref_Global__resize(struct HashMap_str_ref_Global* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Global** HashMap_str_ref_Global__find(struct HashMap_str_ref_Global* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Global** HashMap_str_ref_Global__insert(struct HashMap_str_ref_Global* self, struct str key, struct Global* value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_ref_Global__remove(struct HashMap_str_ref_Global* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_ref_Global__release(struct HashMap_str_ref_Global* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_ref_Global__fill_buckets(struct HashMap_str_ref_Global* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_ref_Global HashMap_str_ref_Global__clone(struct HashMap_str_ref_Global* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Global HashMap_str_ref_Global__iter(struct HashMap_str_ref_Global* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_ref_Global__clear(struct HashMap_str_ref_Global* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Global* HashMap_str_ref_Global__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Global** HashMap_str_ref_Global__Map_str_ref_Global__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Global** HashMap_str_ref_Global__Map_str_ref_Global__insert(void* __self, struct str key, struct Global* value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_ref_Global__Map_str_ref_Global__remove(void* __self, struct str* key);

extern struct trait_Map_str_ref_GlobalVTable HASH_MAP_STR_REF_GLOBAL__VTABLE__MAP;

#endif
