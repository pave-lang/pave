#ifndef PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_ENUM
#define PAVE_HASH_MAP_ITER_USIZE_TYPE_USAGE_ENUM

#include <stdbool.h>

struct HashMapBucket_usize_TypeUsage_Enum;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Enum {
    struct HashMapBucket_usize_TypeUsage_Enum* iter;
    struct HashMapBucket_usize_TypeUsage_Enum* end;
};

struct HashMapIter_usize_TypeUsage_Enum;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Enum__next(struct HashMapIter_usize_TypeUsage_Enum* self);

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Enum* HashMapIter_usize_TypeUsage_Enum__value(struct HashMapIter_usize_TypeUsage_Enum* self);

#endif
