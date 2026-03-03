#ifndef PAVE_HASH_MAP_ITER_STR_STRUCT_CFIELD
#define PAVE_HASH_MAP_ITER_STR_STRUCT_CFIELD

#include <stdbool.h>

struct HashMapBucket_str_StructCField;
struct str;
struct StructCField;

#include <stdio.h>
#include <string.h>

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_StructCField {
    struct HashMapBucket_str_StructCField* iter;
    struct HashMapBucket_str_StructCField* end;
};

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_StructCField__next(struct HashMapIter_str_StructCField* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_StructCField* HashMapIter_str_StructCField__value(struct HashMapIter_str_StructCField* self);

#endif
