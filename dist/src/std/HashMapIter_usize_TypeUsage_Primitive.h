#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_PRIMITIVE
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_PRIMITIVE

#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_Primitive;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Primitive {
    struct HashMapBucket_usize_TypeUsage_Primitive* iter;
    struct HashMapBucket_usize_TypeUsage_Primitive* end;
};

struct HashMapIter_usize_TypeUsage_Primitive;

#line 17 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Primitive__next(struct HashMapIter_usize_TypeUsage_Primitive* self);

#line 22 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Primitive* HashMapIter_usize_TypeUsage_Primitive__value(struct HashMapIter_usize_TypeUsage_Primitive* self);

#endif
