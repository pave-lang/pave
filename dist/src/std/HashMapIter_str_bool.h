#ifndef PAVE_HASH_MAP_ITER_STR_BOOL
#define PAVE_HASH_MAP_ITER_STR_BOOL

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_bool;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_bool {
    struct HashMapBucket_str_bool* iter;
    struct HashMapBucket_str_bool* end;
};
struct HashMapIter_str_bool;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_bool__next(struct HashMapIter_str_bool* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_bool* HashMapIter_str_bool__value(struct HashMapIter_str_bool* self);

#endif
