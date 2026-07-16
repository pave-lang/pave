#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_TUPLE
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_TUPLE

#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_Tuple;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Tuple {
    struct HashMapBucket_usize_TypeUsage_Tuple* iter;
    struct HashMapBucket_usize_TypeUsage_Tuple* end;
};

struct HashMapIter_usize_TypeUsage_Tuple;

#line 17 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Tuple__next(struct HashMapIter_usize_TypeUsage_Tuple* self);

#line 22 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Tuple* HashMapIter_usize_TypeUsage_Tuple__value(struct HashMapIter_usize_TypeUsage_Tuple* self);

#endif
