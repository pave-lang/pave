#ifndef PAVE_HASH_MAP_STR_REF_TRAIT
#define PAVE_HASH_MAP_STR_REF_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_ref_Trait;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Trait {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Trait** buckets;
    struct HashMapBucket_str_ref_Trait* data;
    uintptr_t capacity;
    uintptr_t length;
};

struct HashMap_str_ref_Trait;
struct str;
struct Trait;
#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Trait.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Trait HashMap_str_ref_Trait__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_ref_Trait__resize(struct HashMap_str_ref_Trait* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Trait** HashMap_str_ref_Trait__find(struct HashMap_str_ref_Trait* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Trait** HashMap_str_ref_Trait__insert(struct HashMap_str_ref_Trait* self, struct str key, struct Trait* value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_ref_Trait__remove(struct HashMap_str_ref_Trait* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_ref_Trait__release(struct HashMap_str_ref_Trait* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_ref_Trait__fill_buckets(struct HashMap_str_ref_Trait* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_ref_Trait HashMap_str_ref_Trait__clone(struct HashMap_str_ref_Trait* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Trait HashMap_str_ref_Trait__iter(struct HashMap_str_ref_Trait* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_ref_Trait__clear(struct HashMap_str_ref_Trait* self);

#endif
