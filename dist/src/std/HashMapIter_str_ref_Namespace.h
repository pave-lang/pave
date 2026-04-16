#ifndef PAVE_HASH_MAP_ITER_STR_REF_NAMESPACE
#define PAVE_HASH_MAP_ITER_STR_REF_NAMESPACE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_ref_Namespace;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Namespace {
    struct HashMapBucket_str_ref_Namespace* iter;
    struct HashMapBucket_str_ref_Namespace* end;
};

struct HashMapIter_str_ref_Namespace;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Namespace__next(struct HashMapIter_str_ref_Namespace* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Namespace* HashMapIter_str_ref_Namespace__value(struct HashMapIter_str_ref_Namespace* self);

#endif
