#ifndef PAVE_HASH_MAP_ITER_STR_REF_IMPL_CONST
#define PAVE_HASH_MAP_ITER_STR_REF_IMPL_CONST

#include <stdbool.h>

struct HashMapBucket_str_ref_ImplConst;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_ImplConst {
    struct HashMapBucket_str_ref_ImplConst* iter;
    struct HashMapBucket_str_ref_ImplConst* end;
};

struct HashMapIter_str_ref_ImplConst;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_ImplConst__next(struct HashMapIter_str_ref_ImplConst* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_ImplConst* HashMapIter_str_ref_ImplConst__value(struct HashMapIter_str_ref_ImplConst* self);

#endif
