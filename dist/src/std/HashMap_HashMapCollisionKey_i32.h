#ifndef PAVE_HASH_MAP_HASH_MAP_COLLISION_KEY_I32
#define PAVE_HASH_MAP_HASH_MAP_COLLISION_KEY_I32

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_HashMapCollisionKey_i32;

#line 27 "src/std/HashMap.pv"
struct HashMap_HashMapCollisionKey_i32 {
    struct trait_Allocator allocator;
    struct HashMapBucket_HashMapCollisionKey_i32** buckets;
    struct HashMapBucket_HashMapCollisionKey_i32* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_HashMapCollisionKey_i32.h>
#include <std/HashMapCollisionKey.h>
#include <std/HashMapIter_HashMapCollisionKey_i32.h>
struct HashMap_HashMapCollisionKey_i32;
typedef int32_t HashMapCollisionKey;
struct HashMapBucket_HashMapCollisionKey_i32;

#line 36 "src/std/HashMap.pv"
struct HashMap_HashMapCollisionKey_i32 HashMap_HashMapCollisionKey_i32__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_HashMapCollisionKey_i32 HashMap_HashMapCollisionKey_i32__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_HashMapCollisionKey_i32__resize(struct HashMap_HashMapCollisionKey_i32* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
int32_t* HashMap_HashMapCollisionKey_i32__find(struct HashMap_HashMapCollisionKey_i32* self, HashMapCollisionKey* key);

#line 78 "src/std/HashMap.pv"
int32_t* HashMap_HashMapCollisionKey_i32__insert(struct HashMap_HashMapCollisionKey_i32* self, HashMapCollisionKey key, int32_t value);

#line 108 "src/std/HashMap.pv"
bool HashMap_HashMapCollisionKey_i32__remove(struct HashMap_HashMapCollisionKey_i32* self, HashMapCollisionKey* key);

#line 132 "src/std/HashMap.pv"
void HashMap_HashMapCollisionKey_i32__release(struct HashMap_HashMapCollisionKey_i32* self);

#line 141 "src/std/HashMap.pv"
void HashMap_HashMapCollisionKey_i32__fill_buckets(struct HashMap_HashMapCollisionKey_i32* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_HashMapCollisionKey_i32 HashMap_HashMapCollisionKey_i32__clone(struct HashMap_HashMapCollisionKey_i32* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_HashMapCollisionKey_i32 HashMap_HashMapCollisionKey_i32__iter(struct HashMap_HashMapCollisionKey_i32* self);

#line 183 "src/std/HashMap.pv"
void HashMap_HashMapCollisionKey_i32__clear(struct HashMap_HashMapCollisionKey_i32* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_HashMapCollisionKey_i32* HashMap_HashMapCollisionKey_i32__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
int32_t* HashMap_HashMapCollisionKey_i32__Map_HashMapCollisionKey_i32__find(void* __self, HashMapCollisionKey* key);

#line 215 "src/std/HashMap.pv"
int32_t* HashMap_HashMapCollisionKey_i32__Map_HashMapCollisionKey_i32__insert(void* __self, HashMapCollisionKey key, int32_t value);

#line 245 "src/std/HashMap.pv"
bool HashMap_HashMapCollisionKey_i32__Map_HashMapCollisionKey_i32__remove(void* __self, HashMapCollisionKey* key);

extern struct trait_Map_HashMapCollisionKey_i32VTable HASH_MAP_HASH_MAP_COLLISION_KEY_I32__VTABLE__MAP;

#endif
