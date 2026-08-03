#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_STRUCT
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Struct;

#line 27 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Struct** buckets;
    struct HashMapBucket_usize_TypeUsage_Struct* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>
#include <std/trait_Map_usize_TypeUsage_Struct.h>
struct HashMap_usize_TypeUsage_Struct;
struct TypeUsage_Struct;
struct HashMapBucket_usize_TypeUsage_Struct;

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__resize(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__find(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__insert(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t key, struct TypeUsage_Struct value);

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Struct__remove(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__release(struct HashMap_usize_TypeUsage_Struct* self);

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__fill_buckets(struct HashMap_usize_TypeUsage_Struct* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__clone(struct HashMap_usize_TypeUsage_Struct* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__iter(struct HashMap_usize_TypeUsage_Struct* self);

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__clear(struct HashMap_usize_TypeUsage_Struct* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__Map_usize_TypeUsage_Struct__find(void* __self, uintptr_t* key);

#line 215 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__Map_usize_TypeUsage_Struct__insert(void* __self, uintptr_t key, struct TypeUsage_Struct value);

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Struct__Map_usize_TypeUsage_Struct__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_StructVTable HASH_MAP_USIZE_TYPE_USAGE_STRUCT__VTABLE__MAP;

#endif
