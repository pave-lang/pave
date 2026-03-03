#ifndef PAVE_HASH_MAP_BUCKET_STR_TYPEDEF_C
#define PAVE_HASH_MAP_BUCKET_STR_TYPEDEF_C

#include <std/str.h>
#include <analyzer/TypedefC.h>

struct HashMapBucket_str_TypedefC;
struct str;
struct TypedefC;

#include <stdio.h>
#include <string.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_TypedefC {
    struct str key;
    struct TypedefC value;
    struct HashMapBucket_str_TypedefC* next;
};

#endif
