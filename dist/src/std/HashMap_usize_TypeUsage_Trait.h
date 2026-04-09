#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_TRAIT
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_TRAIT

#include <std/trait_Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_Trait;
struct TypeUsage_Trait;
struct Trait;
struct HashMapIter_usize_TypeUsage_Trait;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Trait** buckets;
    struct HashMapBucket_usize_TypeUsage_Trait* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__resize(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__find(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__insert(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t key, struct TypeUsage_Trait value);

#line 98 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Trait__remove(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t* key);

#line 122 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__release(struct HashMap_usize_TypeUsage_Trait* self);

#line 131 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__fill_buckets(struct HashMap_usize_TypeUsage_Trait* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__clone(struct HashMap_usize_TypeUsage_Trait* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__iter(struct HashMap_usize_TypeUsage_Trait* self);

#line 170 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__clear(struct HashMap_usize_TypeUsage_Trait* self);

#endif
