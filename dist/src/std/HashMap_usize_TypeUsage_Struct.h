#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_STRUCT
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeUsage_Struct;
struct HashMapBucket_usize_TypeUsage_Struct;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Struct** buckets;
    struct HashMapBucket_usize_TypeUsage_Struct* data;
    uintptr_t capacity;
    uintptr_t length;
};
struct HashMap_usize_TypeUsage_Struct;
struct TypeUsage_Struct;
struct TypeUsage_Struct;
#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>


#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__resize(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__find(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeUsage_Struct* HashMap_usize_TypeUsage_Struct__insert(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t key, struct TypeUsage_Struct value);

#line 98 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Struct__remove(struct HashMap_usize_TypeUsage_Struct* self, uintptr_t* key);

#line 122 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__release(struct HashMap_usize_TypeUsage_Struct* self);

#line 131 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__fill_buckets(struct HashMap_usize_TypeUsage_Struct* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__clone(struct HashMap_usize_TypeUsage_Struct* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Struct HashMap_usize_TypeUsage_Struct__iter(struct HashMap_usize_TypeUsage_Struct* self);

#line 170 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Struct__clear(struct HashMap_usize_TypeUsage_Struct* self);

#endif
