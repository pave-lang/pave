#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_TYPE_IMPL
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_TYPE_IMPL

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_TypeImpl;

#line 27 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_TypeImpl {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_TypeImpl** buckets;
    struct HashMapBucket_usize_TypeUsage_TypeImpl* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <compiler/TypeUsage_TypeImpl.h>
#include <std/HashMapIter_usize_TypeUsage_TypeImpl.h>
#include <std/trait_Map_usize_TypeUsage_TypeImpl.h>
struct TypeUsage_TypeImpl;
struct HashMapBucket_usize_TypeUsage_TypeImpl;

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_TypeImpl HashMap_usize_TypeUsage_TypeImpl__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_TypeImpl HashMap_usize_TypeUsage_TypeImpl__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_TypeImpl__resize(struct HashMap_usize_TypeUsage_TypeImpl* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeUsage_TypeImpl* HashMap_usize_TypeUsage_TypeImpl__find(struct HashMap_usize_TypeUsage_TypeImpl* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeUsage_TypeImpl* HashMap_usize_TypeUsage_TypeImpl__insert(struct HashMap_usize_TypeUsage_TypeImpl* self, uintptr_t key, struct TypeUsage_TypeImpl value);

#line 112 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_TypeImpl__remove(struct HashMap_usize_TypeUsage_TypeImpl* self, uintptr_t* key);

#line 136 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_TypeImpl__release(struct HashMap_usize_TypeUsage_TypeImpl* self);

#line 145 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_TypeImpl__fill_buckets(struct HashMap_usize_TypeUsage_TypeImpl* self);

#line 166 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_TypeImpl HashMap_usize_TypeUsage_TypeImpl__clone(struct HashMap_usize_TypeUsage_TypeImpl* self, struct trait_Allocator allocator);

#line 180 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_TypeImpl HashMap_usize_TypeUsage_TypeImpl__iter(struct HashMap_usize_TypeUsage_TypeImpl* self);

#line 187 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_TypeImpl__clear(struct HashMap_usize_TypeUsage_TypeImpl* self);

#line 196 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_TypeImpl* HashMap_usize_TypeUsage_TypeImpl__Index__index(void* __self);

#line 202 "src/std/HashMap.pv"
struct TypeUsage_TypeImpl* HashMap_usize_TypeUsage_TypeImpl__Map_usize_TypeUsage_TypeImpl__find(void* __self, uintptr_t* key);

#line 219 "src/std/HashMap.pv"
struct TypeUsage_TypeImpl* HashMap_usize_TypeUsage_TypeImpl__Map_usize_TypeUsage_TypeImpl__insert(void* __self, uintptr_t key, struct TypeUsage_TypeImpl value);

#line 253 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_TypeImpl__Map_usize_TypeUsage_TypeImpl__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_TypeImplVTable HASH_MAP_USIZE_TYPE_USAGE_TYPE_IMPL__VTABLE__MAP;

#endif
