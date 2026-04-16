#ifndef PAVE_HASH_MAP_BUCKET_STR_FUNCTION
#define PAVE_HASH_MAP_BUCKET_STR_FUNCTION

#include <stdio.h>
#include <string.h>

#include <std/str.h>
#include <analyzer/types/Function.h>
struct HashMapBucket_str_Function;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Function {
    struct str key;
    struct Function value;
    struct HashMapBucket_str_Function* next;
};

#endif
