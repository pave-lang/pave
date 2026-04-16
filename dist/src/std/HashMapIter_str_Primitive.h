#ifndef PAVE_HASH_MAP_ITER_STR_PRIMITIVE
#define PAVE_HASH_MAP_ITER_STR_PRIMITIVE

#include <stdbool.h>

struct HashMapBucket_str_Primitive;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Primitive {
    struct HashMapBucket_str_Primitive* iter;
    struct HashMapBucket_str_Primitive* end;
};

struct HashMapIter_str_Primitive;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Primitive__next(struct HashMapIter_str_Primitive* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Primitive* HashMapIter_str_Primitive__value(struct HashMapIter_str_Primitive* self);

#endif
