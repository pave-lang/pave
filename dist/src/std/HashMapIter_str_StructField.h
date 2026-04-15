#ifndef PAVE_HASH_MAP_ITER_STR_STRUCT_FIELD
#define PAVE_HASH_MAP_ITER_STR_STRUCT_FIELD

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_StructField;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_StructField {
    struct HashMapBucket_str_StructField* iter;
    struct HashMapBucket_str_StructField* end;
};
struct HashMapIter_str_StructField;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_StructField__next(struct HashMapIter_str_StructField* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_StructField* HashMapIter_str_StructField__value(struct HashMapIter_str_StructField* self);

#endif
