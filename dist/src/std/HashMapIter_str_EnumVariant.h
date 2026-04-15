#ifndef PAVE_HASH_MAP_ITER_STR_ENUM_VARIANT
#define PAVE_HASH_MAP_ITER_STR_ENUM_VARIANT

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_EnumVariant;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_EnumVariant {
    struct HashMapBucket_str_EnumVariant* iter;
    struct HashMapBucket_str_EnumVariant* end;
};

struct HashMapIter_str_EnumVariant;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_EnumVariant__next(struct HashMapIter_str_EnumVariant* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_EnumVariant* HashMapIter_str_EnumVariant__value(struct HashMapIter_str_EnumVariant* self);

#endif
