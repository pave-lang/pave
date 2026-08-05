#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_TYPE
#define PAVE_HASH_MAP_ITER_STR_ARRAY_TYPE

#include <stdbool.h>

struct HashMapBucket_str_Array_Type;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_Array_Type {
    struct HashMapBucket_str_Array_Type* iter;
    struct HashMapBucket_str_Array_Type* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_Array_Type__next(struct HashMapIter_str_Array_Type* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_Array_Type* HashMapIter_str_Array_Type__value(struct HashMapIter_str_Array_Type* self);

#endif
