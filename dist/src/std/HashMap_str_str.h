#ifndef PAVE_HASH_MAP_STR_STR
#define PAVE_HASH_MAP_STR_STR

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_str;
struct str;
struct HashMapIter_str_str;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_str {
    struct Allocator allocator;
    struct HashMapBucket_str_str** buckets;
    struct HashMapBucket_str_str* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_str HashMap_str_str__new(struct Allocator allocator);

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
struct HashMap_str_str HashMap_str_str__clone(struct HashMap_str_str* self, struct Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_str HashMap_str_str__iter(struct HashMap_str_str* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_str__clear(struct HashMap_str_str* self);

#endif
