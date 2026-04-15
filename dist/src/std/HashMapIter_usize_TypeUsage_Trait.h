#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_TRAIT
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_TRAIT

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeUsage_Trait;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Trait {
    struct HashMapBucket_usize_TypeUsage_Trait* iter;
    struct HashMapBucket_usize_TypeUsage_Trait* end;
};
struct HashMapIter_usize_TypeUsage_Trait;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Trait__next(struct HashMapIter_usize_TypeUsage_Trait* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Trait* HashMapIter_usize_TypeUsage_Trait__value(struct HashMapIter_usize_TypeUsage_Trait* self);

#endif
