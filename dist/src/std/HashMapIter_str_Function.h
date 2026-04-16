#ifndef PAVE_HASH_MAP_ITER_STR_FUNCTION
#define PAVE_HASH_MAP_ITER_STR_FUNCTION

#include <stdbool.h>

struct HashMapBucket_str_Function;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Function {
    struct HashMapBucket_str_Function* iter;
    struct HashMapBucket_str_Function* end;
};

struct HashMapIter_str_Function;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Function__next(struct HashMapIter_str_Function* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Function* HashMapIter_str_Function__value(struct HashMapIter_str_Function* self);

#endif
