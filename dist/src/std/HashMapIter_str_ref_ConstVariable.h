#ifndef PAVE_HASH_MAP_ITER_STR_REF_CONST_VARIABLE
#define PAVE_HASH_MAP_ITER_STR_REF_CONST_VARIABLE

#include <stdbool.h>

struct HashMapBucket_str_ref_ConstVariable;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_ConstVariable {
    struct HashMapBucket_str_ref_ConstVariable* iter;
    struct HashMapBucket_str_ref_ConstVariable* end;
};

struct HashMapIter_str_ref_ConstVariable;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_ConstVariable__next(struct HashMapIter_str_ref_ConstVariable* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_ConstVariable* HashMapIter_str_ref_ConstVariable__value(struct HashMapIter_str_ref_ConstVariable* self);

#endif
