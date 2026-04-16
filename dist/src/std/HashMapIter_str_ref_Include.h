#ifndef PAVE_HASH_MAP_ITER_STR_REF_INCLUDE
#define PAVE_HASH_MAP_ITER_STR_REF_INCLUDE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_ref_Include;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Include {
    struct HashMapBucket_str_ref_Include* iter;
    struct HashMapBucket_str_ref_Include* end;
};

struct HashMapIter_str_ref_Include;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Include__next(struct HashMapIter_str_ref_Include* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Include* HashMapIter_str_ref_Include__value(struct HashMapIter_str_ref_Include* self);

#endif
