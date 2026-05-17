#ifndef PAVE_HASH_MAP_USIZE_TYPE_USAGE_TUPLE
#define PAVE_HASH_MAP_USIZE_TYPE_USAGE_TUPLE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeUsage_Tuple;

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Tuple {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeUsage_Tuple** buckets;
    struct HashMapBucket_usize_TypeUsage_Tuple* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeUsage_Tuple.h>
#include <compiler/TypeUsage_Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_Tuple.h>
struct HashMap_usize_TypeUsage_Tuple;
struct TypeUsage_Tuple;

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Tuple HashMap_usize_TypeUsage_Tuple__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Tuple HashMap_usize_TypeUsage_Tuple__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Tuple__resize(struct HashMap_usize_TypeUsage_Tuple* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct TypeUsage_Tuple* HashMap_usize_TypeUsage_Tuple__find(struct HashMap_usize_TypeUsage_Tuple* self, uintptr_t* key);

#line 77 "src/std/HashMap.pv"
struct TypeUsage_Tuple* HashMap_usize_TypeUsage_Tuple__insert(struct HashMap_usize_TypeUsage_Tuple* self, uintptr_t key, struct TypeUsage_Tuple value);

#line 105 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Tuple__remove(struct HashMap_usize_TypeUsage_Tuple* self, uintptr_t* key);

#line 129 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Tuple__release(struct HashMap_usize_TypeUsage_Tuple* self);

#line 138 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Tuple__fill_buckets(struct HashMap_usize_TypeUsage_Tuple* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Tuple HashMap_usize_TypeUsage_Tuple__clone(struct HashMap_usize_TypeUsage_Tuple* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Tuple HashMap_usize_TypeUsage_Tuple__iter(struct HashMap_usize_TypeUsage_Tuple* self);

#line 177 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Tuple__clear(struct HashMap_usize_TypeUsage_Tuple* self);

#endif
