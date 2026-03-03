#ifndef PAVE_HASH_MAP_ITER_STR_USIZE
#define PAVE_HASH_MAP_ITER_STR_USIZE

#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_usize;
struct str;

#include <stdio.h>
#include <string.h>

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_usize {
    struct HashMapBucket_str_usize* iter;
    struct HashMapBucket_str_usize* end;
};

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_usize__next(struct HashMapIter_str_usize* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_usize* HashMapIter_str_usize__value(struct HashMapIter_str_usize* self);

#endif
