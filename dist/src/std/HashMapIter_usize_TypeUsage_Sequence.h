#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_SEQUENCE
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_SEQUENCE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeUsage_Sequence;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Sequence {
    struct HashMapBucket_usize_TypeUsage_Sequence* iter;
    struct HashMapBucket_usize_TypeUsage_Sequence* end;
};
struct HashMapIter_usize_TypeUsage_Sequence;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Sequence__next(struct HashMapIter_usize_TypeUsage_Sequence* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Sequence* HashMapIter_usize_TypeUsage_Sequence__value(struct HashMapIter_usize_TypeUsage_Sequence* self);

#endif
