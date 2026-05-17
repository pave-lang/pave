#ifndef PAVE_HASH_MAP_STR_REF_INCLUDE
#define PAVE_HASH_MAP_STR_REF_INCLUDE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Include;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Include {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Include** buckets;
    struct HashMapBucket_str_ref_Include* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Include.h>
struct HashMap_str_ref_Include;
struct str;
struct Include;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_ref_Include__resize(struct HashMap_str_ref_Include* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__find(struct HashMap_str_ref_Include* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__insert(struct HashMap_str_ref_Include* self, struct str key, struct Include* value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_ref_Include__remove(struct HashMap_str_ref_Include* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_ref_Include__release(struct HashMap_str_ref_Include* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_ref_Include__fill_buckets(struct HashMap_str_ref_Include* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__clone(struct HashMap_str_ref_Include* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Include HashMap_str_ref_Include__iter(struct HashMap_str_ref_Include* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_ref_Include__clear(struct HashMap_str_ref_Include* self);

#endif
