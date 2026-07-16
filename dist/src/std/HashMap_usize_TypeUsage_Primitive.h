#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_PRIMITIVE
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_PRIMITIVE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Primitive;

#line 27 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Primitive** buckets;
    struct HashMapBucket_usize_TypeUsage_Primitive* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <compiler/TypeUsage_Primitive.h>
#include <std/HashMapIter_usize_TypeUsage_Primitive.h>
struct HashMap_usize_TypeUsage_Primitive;
struct TypeUsage_Primitive;
struct HashMapBucket_usize_TypeUsage_Primitive;

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__resize(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__find(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__insert(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t key, struct TypeUsage_Primitive value);

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Primitive__remove(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t* key);

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__release(struct HashMap_usize_TypeUsage_Primitive* self);

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__fill_buckets(struct HashMap_usize_TypeUsage_Primitive* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__clone(struct HashMap_usize_TypeUsage_Primitive* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__iter(struct HashMap_usize_TypeUsage_Primitive* self);

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__clear(struct HashMap_usize_TypeUsage_Primitive* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__Map_usize_TypeUsage_Primitive__find(void* __self, uintptr_t* key);

#line 215 "src/std/HashMap.pv"
struct TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__Map_usize_TypeUsage_Primitive__insert(void* __self, uintptr_t key, struct TypeUsage_Primitive value);

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Primitive__Map_usize_TypeUsage_Primitive__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_PrimitiveVTable HASH_MAP_USIZE_TYPE_USAGE_PRIMITIVE__VTABLE__MAP;

#endif
