#ifndef PAVE_HASH_MAP_STR_TRAIT
#define PAVE_HASH_MAP_STR_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Trait;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Trait {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Trait** buckets;
    struct HashMapBucket_str_Trait* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Trait.h>
#include <std/str.h>
#include <analyzer/types/Trait.h>
#include <std/HashMapIter_str_Trait.h>
struct HashMap_str_Trait;
struct str;
struct Trait;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Trait HashMap_str_Trait__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Trait__resize(struct HashMap_str_Trait* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Trait* HashMap_str_Trait__find(struct HashMap_str_Trait* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Trait* HashMap_str_Trait__insert(struct HashMap_str_Trait* self, struct str key, struct Trait value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_Trait__remove(struct HashMap_str_Trait* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_Trait__release(struct HashMap_str_Trait* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Trait__fill_buckets(struct HashMap_str_Trait* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_Trait HashMap_str_Trait__clone(struct HashMap_str_Trait* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_Trait HashMap_str_Trait__iter(struct HashMap_str_Trait* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_Trait__clear(struct HashMap_str_Trait* self);

#endif
