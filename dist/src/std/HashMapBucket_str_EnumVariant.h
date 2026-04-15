#ifndef PAVE_HASH_MAP_BUCKET_STR_ENUM_VARIANT
#define PAVE_HASH_MAP_BUCKET_STR_ENUM_VARIANT

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_EnumVariant;
#include <std/str.h>
#include <analyzer/types/EnumVariant.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_EnumVariant {
    struct str key;
    struct EnumVariant value;
    struct HashMapBucket_str_EnumVariant* next;
};

#endif
