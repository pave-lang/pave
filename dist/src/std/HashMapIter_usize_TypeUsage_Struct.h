#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_STRUCT
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_STRUCT

#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_Struct;
struct TypeUsage_Struct;
struct Struct;

#include <stdio.h>
#include <string.h>

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Struct {
    struct HashMapBucket_usize_TypeUsage_Struct* iter;
    struct HashMapBucket_usize_TypeUsage_Struct* end;
};

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Struct__next(struct HashMapIter_usize_TypeUsage_Struct* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Struct* HashMapIter_usize_TypeUsage_Struct__value(struct HashMapIter_usize_TypeUsage_Struct* self);

#endif
