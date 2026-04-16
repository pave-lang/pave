#ifndef PAVE_HASH_MAP_ITER_STR_ENUM
#define PAVE_HASH_MAP_ITER_STR_ENUM

#include <stdbool.h>

struct HashMapBucket_str_Enum;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Enum {
    struct HashMapBucket_str_Enum* iter;
    struct HashMapBucket_str_Enum* end;
};

struct HashMapIter_str_Enum;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Enum__next(struct HashMapIter_str_Enum* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Enum* HashMapIter_str_Enum__value(struct HashMapIter_str_Enum* self);

#endif
