#ifndef PAVE_HASH_MAP_ITER_STR_STRUCT
#define PAVE_HASH_MAP_ITER_STR_STRUCT

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Struct;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Struct {
    struct HashMapBucket_str_Struct* iter;
    struct HashMapBucket_str_Struct* end;
};
struct HashMapIter_str_Struct;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Struct__next(struct HashMapIter_str_Struct* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Struct* HashMapIter_str_Struct__value(struct HashMapIter_str_Struct* self);

#endif
