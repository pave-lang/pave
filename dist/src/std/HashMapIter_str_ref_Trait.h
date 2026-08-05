#ifndef PAVE_HASH_MAP_ITER_STR_REF_TRAIT
#define PAVE_HASH_MAP_ITER_STR_REF_TRAIT

#include <stdbool.h>

struct HashMapBucket_str_ref_Trait;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Trait {
    struct HashMapBucket_str_ref_Trait* iter;
    struct HashMapBucket_str_ref_Trait* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Trait__next(struct HashMapIter_str_ref_Trait* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_ref_Trait* HashMapIter_str_ref_Trait__value(struct HashMapIter_str_ref_Trait* self);

#endif
