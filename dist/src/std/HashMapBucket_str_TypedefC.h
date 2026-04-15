#ifndef PAVE_HASH_MAP_BUCKET_STR_TYPEDEF_C
#define PAVE_HASH_MAP_BUCKET_STR_TYPEDEF_C

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_TypedefC;
#include <std/str.h>
#include <analyzer/c/TypedefC.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_TypedefC {
    struct str key;
    struct TypedefC value;
    struct HashMapBucket_str_TypedefC* next;
};

#endif
