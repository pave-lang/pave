#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_TYPE_IMPL
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_TYPE_IMPL

#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_TypeImpl;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_TypeImpl {
    struct HashMapBucket_usize_TypeUsage_TypeImpl* iter;
    struct HashMapBucket_usize_TypeUsage_TypeImpl* end;
};

struct HashMapIter_usize_TypeUsage_TypeImpl;

#line 17 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_TypeImpl__next(struct HashMapIter_usize_TypeUsage_TypeImpl* self);

#line 22 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_TypeImpl* HashMapIter_usize_TypeUsage_TypeImpl__value(struct HashMapIter_usize_TypeUsage_TypeImpl* self);

#endif
