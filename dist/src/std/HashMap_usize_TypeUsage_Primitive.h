#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_PRIMITIVE
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_PRIMITIVE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_Primitive;
struct TypeUsage_Primitive;
struct Primitive;
struct HashMapIter_usize_TypeUsage_Primitive;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive {
    struct Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Primitive** buckets;
    struct HashMapBucket_usize_TypeUsage_Primitive* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__resize(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__find(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeUsage_Primitive* HashMap_usize_TypeUsage_Primitive__insert(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t key, struct TypeUsage_Primitive value);

#line 102 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Primitive__remove(struct HashMap_usize_TypeUsage_Primitive* self, uintptr_t* key);

#line 126 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__release(struct HashMap_usize_TypeUsage_Primitive* self);

#line 135 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__fill_buckets(struct HashMap_usize_TypeUsage_Primitive* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__clone(struct HashMap_usize_TypeUsage_Primitive* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Primitive HashMap_usize_TypeUsage_Primitive__iter(struct HashMap_usize_TypeUsage_Primitive* self);

#line 174 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Primitive__clear(struct HashMap_usize_TypeUsage_Primitive* self);

#endif
