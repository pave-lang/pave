#ifndef PAVE_HASH_MAP_STR_REF_GLOBAL
#define PAVE_HASH_MAP_STR_REF_GLOBAL

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Global;

#line 26 "src/std/HashMap.pv"
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

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Global HashMap_str_ref_Global__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_ref_Global HashMap_str_ref_Global__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_ref_Global__resize(struct HashMap_str_ref_Global* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Global** HashMap_str_ref_Global__find(struct HashMap_str_ref_Global* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Global** HashMap_str_ref_Global__insert(struct HashMap_str_ref_Global* self, struct str key, struct Global* value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_ref_Global__remove(struct HashMap_str_ref_Global* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_ref_Global__release(struct HashMap_str_ref_Global* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_ref_Global__fill_buckets(struct HashMap_str_ref_Global* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_ref_Global HashMap_str_ref_Global__clone(struct HashMap_str_ref_Global* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Global HashMap_str_ref_Global__iter(struct HashMap_str_ref_Global* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_ref_Global__clear(struct HashMap_str_ref_Global* self);

#endif
