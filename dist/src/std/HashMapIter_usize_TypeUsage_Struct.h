#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_STRUCT
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_STRUCT

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeUsage_Struct;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Struct {
    struct HashMapBucket_usize_TypeUsage_Struct* iter;
    struct HashMapBucket_usize_TypeUsage_Struct* end;
};

struct HashMapIter_usize_TypeUsage_Struct;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Struct__next(struct HashMapIter_usize_TypeUsage_Struct* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Struct* HashMapIter_usize_TypeUsage_Struct__value(struct HashMapIter_usize_TypeUsage_Struct* self);

#endif
