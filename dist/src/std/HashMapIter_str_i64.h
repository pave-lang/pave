#ifndef PAVE_HASH_MAP_ITER_STR_I64
#define PAVE_HASH_MAP_ITER_STR_I64

#include <stdbool.h>

struct HashMapBucket_str_i64;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_i64 {
    struct HashMapBucket_str_i64* iter;
    struct HashMapBucket_str_i64* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_i64__next(struct HashMapIter_str_i64* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_i64* HashMapIter_str_i64__value(struct HashMapIter_str_i64* self);

#endif
