#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_TRAIT
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Trait;

#line 27 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Trait** buckets;
    struct HashMapBucket_usize_TypeUsage_Trait* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <compiler/TypeUsage_Trait.h>
#include <std/HashMapIter_usize_TypeUsage_Trait.h>
#include <std/trait_Map_usize_TypeUsage_Trait.h>
struct TypeUsage_Trait;
struct HashMapBucket_usize_TypeUsage_Trait;

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__resize(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__find(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__insert(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t key, struct TypeUsage_Trait value);

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Trait__remove(struct HashMap_usize_TypeUsage_Trait* self, uintptr_t* key);

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__release(struct HashMap_usize_TypeUsage_Trait* self);

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__fill_buckets(struct HashMap_usize_TypeUsage_Trait* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__clone(struct HashMap_usize_TypeUsage_Trait* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Trait HashMap_usize_TypeUsage_Trait__iter(struct HashMap_usize_TypeUsage_Trait* self);

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Trait__clear(struct HashMap_usize_TypeUsage_Trait* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__Map_usize_TypeUsage_Trait__find(void* __self, uintptr_t* key);

#line 215 "src/std/HashMap.pv"
struct TypeUsage_Trait* HashMap_usize_TypeUsage_Trait__Map_usize_TypeUsage_Trait__insert(void* __self, uintptr_t key, struct TypeUsage_Trait value);

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Trait__Map_usize_TypeUsage_Trait__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_TraitVTable HASH_MAP_USIZE_TYPE_USAGE_TRAIT__VTABLE__MAP;

#endif
