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

#line 39 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__resize(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__find(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 77 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__insert(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t key, struct TypeUsage_Struct value);

#line 105 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Struct__remove(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 129 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__release(struct HashMap_usize_TypeUsage_Struct* self);

#line 138 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__fill_buckets(struct HashMap_usize_TypeUsage_Struct* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__clone(struct HashMap_usize_TypeUsage_Struct* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__iter(struct HashMap_usize_TypeUsage_Struct* self);

#line 177 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__clear(struct HashMap_usize_TypeUsage_Struct* self);

#endif
