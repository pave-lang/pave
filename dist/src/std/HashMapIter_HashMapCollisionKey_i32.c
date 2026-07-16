#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_HashMapCollisionKey_i32.h>
#include <std/HashMapIter_HashMapCollisionKey_i32.h>
#include <tuple_HashMapCollisionKey_i32.h>
#include <std/HashMapIter_HashMapCollisionKey_i32.h>

#include <std/HashMapIter_HashMapCollisionKey_i32.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_HashMapCollisionKey_i32__next(struct HashMapIter_HashMapCollisionKey_i32* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_HashMapCollisionKey_i32* HashMapIter_HashMapCollisionKey_i32__value(struct HashMapIter_HashMapCollisionKey_i32* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_HashMapCollisionKey_i32*)(self->iter);
}
