#ifndef PAVE_HASH_MAP_ITER_STR_TYPEDEF_C
#define PAVE_HASH_MAP_ITER_STR_TYPEDEF_C

#include <stdbool.h>

struct HashMapBucket_str_TypedefC;
struct str;
struct TypedefC;

#include <stdio.h>
#include <string.h>

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_TypedefC {
    struct HashMapBucket_str_TypedefC* iter;
    struct HashMapBucket_str_TypedefC* end;
};

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_TypedefC__next(struct HashMapIter_str_TypedefC* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_TypedefC* HashMapIter_str_TypedefC__value(struct HashMapIter_str_TypedefC* self);

#endif
