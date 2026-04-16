#ifndef PAVE_HASH_MAP_ITER_STR_USIZE
#define PAVE_HASH_MAP_ITER_STR_USIZE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_usize;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_usize {
    struct HashMapBucket_str_usize* iter;
    struct HashMapBucket_str_usize* end;
};

struct HashMapIter_str_usize;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_usize__next(struct HashMapIter_str_usize* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_usize* HashMapIter_str_usize__value(struct HashMapIter_str_usize* self);

#endif
