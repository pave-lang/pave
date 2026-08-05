#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_REF_ENUM
#define PAVE_HASH_MAP_ITER_STR_ARRAY_REF_ENUM

#include <stdbool.h>

struct HashMapBucket_str_Array_ref_Enum;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_Array_ref_Enum {
    struct HashMapBucket_str_Array_ref_Enum* iter;
    struct HashMapBucket_str_Array_ref_Enum* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_Array_ref_Enum__next(struct HashMapIter_str_Array_ref_Enum* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_Array_ref_Enum* HashMapIter_str_Array_ref_Enum__value(struct HashMapIter_str_Array_ref_Enum* self);

#endif
