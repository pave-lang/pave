#ifndef PAVE_HASH_MAP_BUCKET_STR_STRUCT_CFIELD
#define PAVE_HASH_MAP_BUCKET_STR_STRUCT_CFIELD

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_StructCField;
#include <std/str.h>
#include <analyzer/c/StructCField.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_StructCField {
    struct str key;
    struct StructCField value;
    struct HashMapBucket_str_StructCField* next;
};

#endif
