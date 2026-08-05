#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Sequence;

#line 27 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Sequence** buckets;
    struct HashMapBucket_usize_TypeUsage_Sequence* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <compiler/TypeUsage_Sequence.h>
#include <std/HashMapIter_usize_TypeUsage_Sequence.h>
#include <std/trait_Map_usize_TypeUsage_Sequence.h>
struct TypeUsage_Sequence;
struct HashMapBucket_usize_TypeUsage_Sequence;

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__resize(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__find(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__insert(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t key, struct TypeUsage_Sequence value);

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Sequence__remove(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key);

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__release(struct HashMap_usize_TypeUsage_Sequence* self);

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__fill_buckets(struct HashMap_usize_TypeUsage_Sequence* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__clone(struct HashMap_usize_TypeUsage_Sequence* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__iter(struct HashMap_usize_TypeUsage_Sequence* self);

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__clear(struct HashMap_usize_TypeUsage_Sequence* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__Map_usize_TypeUsage_Sequence__find(void* __self, uintptr_t* key);

#line 215 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__Map_usize_TypeUsage_Sequence__insert(void* __self, uintptr_t key, struct TypeUsage_Sequence value);

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Sequence__Map_usize_TypeUsage_Sequence__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeUsage_SequenceVTable HASH_MAP_USIZE_TYPE_USAGE_SEQUENCE__VTABLE__MAP;

#endif
