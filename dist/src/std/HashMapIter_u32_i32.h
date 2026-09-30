#ifndef PAVE_HASH_MAP_ITER_U32_I32
#define PAVE_HASH_MAP_ITER_U32_I32

#include <stdbool.h>

struct HashMapBucket_u32_i32;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_u32_i32 {
    struct HashMapBucket_u32_i32* iter;
    struct HashMapBucket_u32_i32* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_u32_i32__next(struct HashMapIter_u32_i32* self);

#line 22 "src/std/HashMap.pv"
struct tuple_u32_i32* HashMapIter_u32_i32__value(struct HashMapIter_u32_i32* self);

#endif
