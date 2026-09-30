#ifndef PAVE_HASH_MAP_COLLISION_KEY
#define PAVE_HASH_MAP_COLLISION_KEY

#include <stdint.h>
#include <stdbool.h>

#line 278 "src/std/HashMap.pv"
typedef int32_t HashMapCollisionKey;

#include <std/trait_Hash.h>
#include <std/Hash.h>

#line 281 "src/std/HashMap.pv"
Hash HashMapCollisionKey__Hash__hash(void* __self);

#line 285 "src/std/HashMap.pv"
bool HashMapCollisionKey__Eq_HashMapCollisionKey__eq(HashMapCollisionKey self, HashMapCollisionKey other);

extern struct trait_HashVTable HASH_MAP_COLLISION_KEY__VTABLE__HASH;

#endif
