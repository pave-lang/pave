#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_REF_STRUCT
#define PAVE_HASH_MAP_ITER_STR_ARRAY_REF_STRUCT

#include <stdbool.h>

struct HashMapBucket_str_Array_ref_Struct;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_Array_ref_Struct {
    struct HashMapBucket_str_Array_ref_Struct* iter;
    struct HashMapBucket_str_Array_ref_Struct* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_Array_ref_Struct__next(struct HashMapIter_str_Array_ref_Struct* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_Array_ref_Struct* HashMapIter_str_Array_ref_Struct__value(struct HashMapIter_str_Array_ref_Struct* self);

#endif
