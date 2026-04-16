#ifndef PAVE_HASH_MAP_BUCKET_STR_ENUM_CVALUE
#define PAVE_HASH_MAP_BUCKET_STR_ENUM_CVALUE

#include <stdio.h>
#include <string.h>

#include <std/str.h>
#include <analyzer/c/EnumCValue.h>
struct HashMapBucket_str_EnumCValue;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_EnumCValue {
    struct str key;
    struct EnumCValue value;
    struct HashMapBucket_str_EnumCValue* next;
};

#endif
