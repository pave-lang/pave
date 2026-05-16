#ifndef PAVE_HASH_MAP_STR_BOOL
#define PAVE_HASH_MAP_STR_BOOL

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_bool;

#line 26 "src/std/HashMap.pv"
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

#line 35 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__new(struct trait_Allocator allocator);

#line 50 "src/std/HashMap.pv"
void HashMap_str_bool__resize(struct HashMap_str_bool* self, uintptr_t new_capacity);

#line 57 "src/std/HashMap.pv"
bool* HashMap_str_bool__find(struct HashMap_str_bool* self, struct str* key);

#line 74 "src/std/HashMap.pv"
bool* HashMap_str_bool__insert(struct HashMap_str_bool* self, struct str key, bool value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_bool__remove(struct HashMap_str_bool* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_bool__release(struct HashMap_str_bool* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_bool__fill_buckets(struct HashMap_str_bool* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__clone(struct HashMap_str_bool* self, struct trait_Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_bool HashMap_str_bool__iter(struct HashMap_str_bool* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_bool__clear(struct HashMap_str_bool* self);

#endif
