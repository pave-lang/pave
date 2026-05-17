#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE

#include <stdint.h>
#include <stdbool.h>

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

#line 39 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__resize(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__find(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key);

#line 77 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__insert(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t key, struct TypeUsage_Sequence value);

#line 105 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Sequence__remove(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key);

#line 129 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__release(struct HashMap_usize_TypeUsage_Sequence* self);

#line 138 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__fill_buckets(struct HashMap_usize_TypeUsage_Sequence* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__clone(struct HashMap_usize_TypeUsage_Sequence* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__iter(struct HashMap_usize_TypeUsage_Sequence* self);

#line 177 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__clear(struct HashMap_usize_TypeUsage_Sequence* self);

#endif
