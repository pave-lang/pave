#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_DIAGNOSTIC
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_DIAGNOSTIC

#include <stdio.h>
#include <string.h>

#include <std/str.h>
#include <std/Array_Diagnostic.h>
struct HashMapBucket_str_Array_Diagnostic;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_Diagnostic {
    struct str key;
    struct Array_Diagnostic value;
    struct HashMapBucket_str_Array_Diagnostic* next;
};

#endif
