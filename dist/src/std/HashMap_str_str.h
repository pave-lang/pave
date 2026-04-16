#ifndef PAVE_HASH_MAP_STR_STR
#define PAVE_HASH_MAP_STR_STR

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_str;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_str {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_str** buckets;
    struct HashMapBucket_str_str* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_str.h>
#include <std/str.h>
#include <std/HashMapIter_str_str.h>
struct HashMap_str_str;
struct str;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_str HashMap_str_str__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_str__resize(struct HashMap_str_str* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct str* HashMap_str_str__find(struct HashMap_str_str* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct str* HashMap_str_str__insert(struct HashMap_str_str* self, struct str key, struct str value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_str__remove(struct HashMap_str_str* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_str__release(struct HashMap_str_str* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_str__fill_buckets(struct HashMap_str_str* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_str HashMap_str_str__clone(struct HashMap_str_str* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_str HashMap_str_str__iter(struct HashMap_str_str* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_str__clear(struct HashMap_str_str* self);

#endif
