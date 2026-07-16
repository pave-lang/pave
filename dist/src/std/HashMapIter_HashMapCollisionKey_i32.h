#ifndef PAVE_HASH_MAP_ITER_HASH_MAP_COLLISION_KEY_I32
#define PAVE_HASH_MAP_ITER_HASH_MAP_COLLISION_KEY_I32

#include <stdbool.h>

struct HashMapBucket_HashMapCollisionKey_i32;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_HashMapCollisionKey_i32 {
    struct HashMapBucket_HashMapCollisionKey_i32* iter;
    struct HashMapBucket_HashMapCollisionKey_i32* end;
};

struct HashMapIter_HashMapCollisionKey_i32;

#line 17 "src/std/HashMap.pv"
bool HashMapIter_HashMapCollisionKey_i32__next(struct HashMapIter_HashMapCollisionKey_i32* self);

#line 22 "src/std/HashMap.pv"
struct tuple_HashMapCollisionKey_i32* HashMapIter_HashMapCollisionKey_i32__value(struct HashMapIter_HashMapCollisionKey_i32* self);

#endif
