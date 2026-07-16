#ifndef PAVE_HASH_MAP_BUCKET_HASH_MAP_COLLISION_KEY_I32
#define PAVE_HASH_MAP_BUCKET_HASH_MAP_COLLISION_KEY_I32

#include <stdint.h>

#include <std/HashMapCollisionKey.h>
struct HashMapBucket_HashMapCollisionKey_i32;

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_HashMapCollisionKey_i32 {
    HashMapCollisionKey key;
    int32_t value;
    struct HashMapBucket_HashMapCollisionKey_i32* next;
};

#endif
