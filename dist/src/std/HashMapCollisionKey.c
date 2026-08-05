#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/Hash.h>
#include <std/HashMapCollisionKey.h>

#include <std/HashMapCollisionKey.h>

#line 273 "src/std/HashMap.pv"
Hash HashMapCollisionKey__Hash__hash(void* __self) {
    HashMapCollisionKey* self = __self; (void)self;
    #line 273 "src/std/HashMap.pv"
    return 1;
}

#line 277 "src/std/HashMap.pv"
bool HashMapCollisionKey__Eq_HashMapCollisionKey__eq(HashMapCollisionKey self, HashMapCollisionKey other) {
    #line 278 "src/std/HashMap.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable HASH_MAP_COLLISION_KEY__VTABLE__HASH = { .fn_hash = &HashMapCollisionKey__Hash__hash };
