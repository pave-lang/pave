#ifndef PAVE_HASH_MAP_ITER_STR_REF_MODULE
#define PAVE_HASH_MAP_ITER_STR_REF_MODULE

#include <stdbool.h>

struct HashMapBucket_str_ref_Module;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Module {
    struct HashMapBucket_str_ref_Module* iter;
    struct HashMapBucket_str_ref_Module* end;
};

struct HashMapIter_str_ref_Module;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Module__next(struct HashMapIter_str_ref_Module* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Module* HashMapIter_str_ref_Module__value(struct HashMapIter_str_ref_Module* self);

#endif
