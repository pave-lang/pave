#ifndef PAVE_HASH_MAP_ITER_STR_STR
#define PAVE_HASH_MAP_ITER_STR_STR

#include <stdbool.h>

struct HashMapBucket_str_str;
struct str;

#include <stdio.h>
#include <string.h>

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_str {
    struct HashMapBucket_str_str* iter;
    struct HashMapBucket_str_str* end;
};

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_str__next(struct HashMapIter_str_str* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_str* HashMapIter_str_str__value(struct HashMapIter_str_str* self);

#endif
