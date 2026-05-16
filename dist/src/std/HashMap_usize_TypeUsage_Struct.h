#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_STRUCT
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Struct;

#line 26 "src/std/HashMap.pv"
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
struct HashMap_usize_TypeUsage_Struct;
struct TypeUsage_Struct;

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__new(struct trait_Allocator allocator);

#line 50 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__resize(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t new_capacity);

#line 57 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__find(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 74 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__insert(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t key, struct TypeUsage_Struct value);

#line 102 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Struct__remove(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 126 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__release(struct HashMap_usize_TypeUsage_Struct* self);

#line 135 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__fill_buckets(struct HashMap_usize_TypeUsage_Struct* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__clone(struct HashMap_usize_TypeUsage_Struct* self, struct trait_Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__iter(struct HashMap_usize_TypeUsage_Struct* self);

#line 174 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__clear(struct HashMap_usize_TypeUsage_Struct* self);

#endif
