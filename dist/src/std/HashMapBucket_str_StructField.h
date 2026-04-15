#ifndef PAVE_HASH_MAP_BUCKET_STR_STRUCT_FIELD
#define PAVE_HASH_MAP_BUCKET_STR_STRUCT_FIELD

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_StructField;
#include <std/str.h>
#include <analyzer/types/StructField.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_StructField {
    struct str key;
    struct StructField value;
    struct HashMapBucket_str_StructField* next;
};

#endif
