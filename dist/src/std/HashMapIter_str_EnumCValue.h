#ifndef PAVE_HASH_MAP_ITER_STR_ENUM_CVALUE
#define PAVE_HASH_MAP_ITER_STR_ENUM_CVALUE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_EnumCValue;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_EnumCValue {
    struct HashMapBucket_str_EnumCValue* iter;
    struct HashMapBucket_str_EnumCValue* end;
};

struct HashMapIter_str_EnumCValue;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_EnumCValue__next(struct HashMapIter_str_EnumCValue* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_EnumCValue* HashMapIter_str_EnumCValue__value(struct HashMapIter_str_EnumCValue* self);

#endif
