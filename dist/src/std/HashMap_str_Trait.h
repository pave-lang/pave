#ifndef PAVE_HASH_MAP_STR_TRAIT
#define PAVE_HASH_MAP_STR_TRAIT

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_Trait;
struct str;
struct Trait;
struct HashMapIter_str_Trait;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Trait {
    struct Allocator allocator;
    struct HashMapBucket_str_Trait** buckets;
    struct HashMapBucket_str_Trait* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Trait HashMap_str_Trait__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Trait__resize(struct HashMap_str_Trait* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Trait* HashMap_str_Trait__find(struct HashMap_str_Trait* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Trait* HashMap_str_Trait__insert(struct HashMap_str_Trait* self, struct str key, struct Trait value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_Trait__remove(struct HashMap_str_Trait* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_Trait__release(struct HashMap_str_Trait* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_Trait__fill_buckets(struct HashMap_str_Trait* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_Trait HashMap_str_Trait__clone(struct HashMap_str_Trait* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_Trait HashMap_str_Trait__iter(struct HashMap_str_Trait* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_Trait__clear(struct HashMap_str_Trait* self);

#endif
