#ifndef PAVE_HASH_MAP_ITER_STR_REF_GLOBAL
#define PAVE_HASH_MAP_ITER_STR_REF_GLOBAL

#include <stdbool.h>

struct HashMapBucket_str_ref_Global;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Global {
    struct HashMapBucket_str_ref_Global* iter;
    struct HashMapBucket_str_ref_Global* end;
};

struct HashMapIter_str_ref_Global;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Global__next(struct HashMapIter_str_ref_Global* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Global* HashMapIter_str_ref_Global__value(struct HashMapIter_str_ref_Global* self);

#endif
