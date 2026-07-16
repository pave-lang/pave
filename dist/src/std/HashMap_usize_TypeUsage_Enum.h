#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_ENUM
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Enum;

#line 27 "src/std/HashMap.pv"
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

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__resize(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__find(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__insert(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t key, struct TypeUsage_Enum value);

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Enum__remove(struct HashMap_usize_TypeUsage_Enum* self, uintptr_t* key);

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__release(struct HashMap_usize_TypeUsage_Enum* self);

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__fill_buckets(struct HashMap_usize_TypeUsage_Enum* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__clone(struct HashMap_usize_TypeUsage_Enum* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Enum HashMap_usize_TypeUsage_Enum__iter(struct HashMap_usize_TypeUsage_Enum* self);

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Enum__clear(struct HashMap_usize_TypeUsage_Enum* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__Map_usize_TypeUsage_Enum__find(void* __self, uintptr_t* key);

#line 215 "src/std/HashMap.pv"
struct TypeUsage_Enum* HashMap_usize_TypeUsage_Enum__Map_usize_TypeUsage_Enum__insert(void* __self, uintptr_t key, struct TypeUsage_Enum value);

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Enum__Map_usize_TypeUsage_Enum__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_EnumVTable HASH_MAP_USIZE_TYPE_USAGE_ENUM__VTABLE__MAP;

#endif
