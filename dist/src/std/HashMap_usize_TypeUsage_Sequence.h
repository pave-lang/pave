#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Sequence;

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Sequence** buckets;
    struct HashMapBucket_usize_TypeUsage_Sequence* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>
#include <compiler/TypeUsage_Sequence.h>
#include <std/HashMapIter_usize_TypeUsage_Sequence.h>
struct HashMap_usize_TypeUsage_Sequence;
struct TypeUsage_Sequence;

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__resize(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__find(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__insert(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t key, struct TypeUsage_Sequence value);

#line 98 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Sequence__remove(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key);

#line 122 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__release(struct HashMap_usize_TypeUsage_Sequence* self);

#line 131 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__fill_buckets(struct HashMap_usize_TypeUsage_Sequence* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__clone(struct HashMap_usize_TypeUsage_Sequence* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__iter(struct HashMap_usize_TypeUsage_Sequence* self);

#line 170 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__clear(struct HashMap_usize_TypeUsage_Sequence* self);

#endif
