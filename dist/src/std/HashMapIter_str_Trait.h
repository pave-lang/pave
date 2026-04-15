#ifndef PAVE_HASH_MAP_ITER_STR_TRAIT
#define PAVE_HASH_MAP_ITER_STR_TRAIT

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Trait;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Trait {
    struct HashMapBucket_str_Trait* iter;
    struct HashMapBucket_str_Trait* end;
};
struct HashMapIter_str_Trait;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Trait__next(struct HashMapIter_str_Trait* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Trait* HashMapIter_str_Trait__value(struct HashMapIter_str_Trait* self);

#endif
