#ifndef PAVE_HASH_MAP_ITER_U32_TYPE
#define PAVE_HASH_MAP_ITER_U32_TYPE

#include <stdbool.h>

struct HashMapBucket_u32_Type;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_u32_Type {
    struct HashMapBucket_u32_Type* iter;
    struct HashMapBucket_u32_Type* end;
};

struct HashMapIter_u32_Type;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_u32_Type__next(struct HashMapIter_u32_Type* self);

#line 21 "src/std/HashMap.pv"
struct tuple_u32_Type* HashMapIter_u32_Type__value(struct HashMapIter_u32_Type* self);

#endif
