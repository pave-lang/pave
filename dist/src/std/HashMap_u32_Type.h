#ifndef PAVE_HASH_MAP_U32_TYPE
#define PAVE_HASH_MAP_U32_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_u32_Type;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_u32_Type {
    struct trait_Allocator allocator;
    struct HashMapBucket_u32_Type** buckets;
    struct HashMapBucket_u32_Type* data;
    uintptr_t capacity;
    uintptr_t length;
};

struct HashMap_u32_Type;
struct Type;
struct Type;
#include <std/trait_Allocator.h>
#include <std/HashMap_u32_Type.h>
#include <analyzer/types/Type.h>
#include <std/HashMapIter_u32_Type.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_u32_Type HashMap_u32_Type__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_u32_Type__resize(struct HashMap_u32_Type* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Type* HashMap_u32_Type__find(struct HashMap_u32_Type* self, uint32_t* key);

#line 70 "src/std/HashMap.pv"
struct Type* HashMap_u32_Type__insert(struct HashMap_u32_Type* self, uint32_t key, struct Type value);

#line 98 "src/std/HashMap.pv"
bool HashMap_u32_Type__remove(struct HashMap_u32_Type* self, uint32_t* key);

#line 122 "src/std/HashMap.pv"
void HashMap_u32_Type__release(struct HashMap_u32_Type* self);

#line 131 "src/std/HashMap.pv"
void HashMap_u32_Type__fill_buckets(struct HashMap_u32_Type* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_u32_Type HashMap_u32_Type__clone(struct HashMap_u32_Type* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_u32_Type HashMap_u32_Type__iter(struct HashMap_u32_Type* self);

#line 170 "src/std/HashMap.pv"
void HashMap_u32_Type__clear(struct HashMap_u32_Type* self);

#endif
