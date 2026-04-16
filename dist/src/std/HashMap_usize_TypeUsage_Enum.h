#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_ENUM
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Enum;

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Enum** buckets;
    struct HashMapBucket_usize_TypeUsage_Enum* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/HashMapIter_usize_TypeUsage_Enum.h>
struct HashMap_usize_TypeUsage_Enum;
struct TypeUsage_Enum;

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__resize(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__find(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__insert(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t key, struct TypeUsage_Enum value);

#line 98 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Enum__remove(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t* key);

#line 122 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__release(struct HashMap_usize_TypeUsage_Enum* self);

#line 131 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__fill_buckets(struct HashMap_usize_TypeUsage_Enum* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__clone(struct HashMap_usize_TypeUsage_Enum* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__iter(struct HashMap_usize_TypeUsage_Enum* self);

#line 170 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__clear(struct HashMap_usize_TypeUsage_Enum* self);

#endif
