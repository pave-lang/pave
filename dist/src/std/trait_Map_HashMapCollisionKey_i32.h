#ifndef PAVE_TRAIT_MAP_HASH_MAP_COLLISION_KEY_I32
#define PAVE_TRAIT_MAP_HASH_MAP_COLLISION_KEY_I32

#include <stdint.h>
#include <stdbool.h>

#include <std/HashMapCollisionKey.h>
typedef int32_t HashMapCollisionKey;

#line 1 "src/std/Map.pv"
struct trait_Map_HashMapCollisionKey_i32VTable {
    #line 2 "src/std/Map.pv"
    int32_t* (*fn_find)(void* __self, HashMapCollisionKey* key);
    #line 3 "src/std/Map.pv"
    int32_t* (*fn_insert)(void* __self, HashMapCollisionKey key, int32_t value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, HashMapCollisionKey* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_HashMapCollisionKey_i32 {
    const struct trait_Map_HashMapCollisionKey_i32VTable* vtable;
    void* instance;
};

#endif
