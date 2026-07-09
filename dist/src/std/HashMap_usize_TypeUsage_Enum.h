#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_ENUM
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_ENUM

#include <stdint.h>
#include <stdbool.h>

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
struct HashMapBucket_usize_TypeUsage_Enum;

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__resize(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__find(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t* key);

#line 77 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__insert(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t key, struct TypeUsage_Enum value);

#line 107 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Enum__remove(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t* key);

#line 131 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__release(struct HashMap_usize_TypeUsage_Enum* self);

#line 140 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__fill_buckets(struct HashMap_usize_TypeUsage_Enum* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__clone(struct HashMap_usize_TypeUsage_Enum* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__iter(struct HashMap_usize_TypeUsage_Enum* self);

#line 182 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__clear(struct HashMap_usize_TypeUsage_Enum* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__Index__index(void* __self);

#line 197 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__Map_usize_TypeUsage_Enum__find(void* __self, uintptr_t* key);

#line 214 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__Map_usize_TypeUsage_Enum__insert(void* __self, uintptr_t key, struct TypeUsage_Enum value);

#line 244 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Enum__Map_usize_TypeUsage_Enum__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_EnumVTable HASH_MAP_USIZE_TYPE_USAGE_ENUM__VTABLE__MAP;

#endif
