#ifndef PAVE_HASH_MAP_ITER_STR_REF_PRIMITIVE
#define PAVE_HASH_MAP_ITER_STR_REF_PRIMITIVE

#include <stdbool.h>

struct HashMapBucket_str_ref_Primitive;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Primitive {
    struct HashMapBucket_str_ref_Primitive* iter;
    struct HashMapBucket_str_ref_Primitive* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Primitive__next(struct HashMapIter_str_ref_Primitive* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_ref_Primitive* HashMapIter_str_ref_Primitive__value(struct HashMapIter_str_ref_Primitive* self);

#endif
