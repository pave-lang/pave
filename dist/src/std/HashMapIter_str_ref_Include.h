#ifndef PAVE_HASH_MAP_ITER_STR_REF_INCLUDE
#define PAVE_HASH_MAP_ITER_STR_REF_INCLUDE

#include <stdbool.h>

struct HashMapBucket_str_ref_Include;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Include {
    struct HashMapBucket_str_ref_Include* iter;
    struct HashMapBucket_str_ref_Include* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Include__next(struct HashMapIter_str_ref_Include* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_ref_Include* HashMapIter_str_ref_Include__value(struct HashMapIter_str_ref_Include* self);

#endif
