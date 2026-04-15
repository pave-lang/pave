#ifndef PAVE_HASH_MAP_ITER_STR_REF_TYPE
#define PAVE_HASH_MAP_ITER_STR_REF_TYPE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_ref_Type;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Type {
    struct HashMapBucket_str_ref_Type* iter;
    struct HashMapBucket_str_ref_Type* end;
};
struct HashMapIter_str_ref_Type;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Type__next(struct HashMapIter_str_ref_Type* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Type* HashMapIter_str_ref_Type__value(struct HashMapIter_str_ref_Type* self);

#endif
