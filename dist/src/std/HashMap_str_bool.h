#ifndef PAVE_HASH_MAP_STR_BOOL
#define PAVE_HASH_MAP_STR_BOOL

#include <std/Allocator.h>
#include <stdbool.h>
#include <stdint.h>

struct HashMapBucket_str_bool;
struct str;
struct HashMapIter_str_bool;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_bool {
    struct Allocator allocator;
    struct HashMapBucket_str_bool** buckets;
    struct HashMapBucket_str_bool* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_bool__resize(struct HashMap_str_bool* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
bool* HashMap_str_bool__find(struct HashMap_str_bool* self, struct str* key);

#line 70 "src/std/HashMap.pv"
bool* HashMap_str_bool__insert(struct HashMap_str_bool* self, struct str key, bool value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_bool__remove(struct HashMap_str_bool* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_bool__release(struct HashMap_str_bool* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_bool__fill_buckets(struct HashMap_str_bool* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_bool HashMap_str_bool__clone(struct HashMap_str_bool* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_bool HashMap_str_bool__iter(struct HashMap_str_bool* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_bool__clear(struct HashMap_str_bool* self);

#endif
