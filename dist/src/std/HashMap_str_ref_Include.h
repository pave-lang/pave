#ifndef PAVE_HASH_MAP_STR_REF_INCLUDE
#define PAVE_HASH_MAP_STR_REF_INCLUDE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_ref_Include;
struct str;
struct Include;
struct HashMapIter_str_ref_Include;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Include {
    struct Allocator allocator;
    struct HashMapBucket_str_ref_Include** buckets;
    struct HashMapBucket_str_ref_Include* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_ref_Include__resize(struct HashMap_str_ref_Include* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__find(struct HashMap_str_ref_Include* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__insert(struct HashMap_str_ref_Include* self, struct str key, struct Include* value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_ref_Include__remove(struct HashMap_str_ref_Include* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_ref_Include__release(struct HashMap_str_ref_Include* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_ref_Include__fill_buckets(struct HashMap_str_ref_Include* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__clone(struct HashMap_str_ref_Include* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Include HashMap_str_ref_Include__iter(struct HashMap_str_ref_Include* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_ref_Include__clear(struct HashMap_str_ref_Include* self);

#endif
