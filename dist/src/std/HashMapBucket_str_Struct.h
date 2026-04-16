#ifndef PAVE_HASH_MAP_BUCKET_STR_STRUCT
#define PAVE_HASH_MAP_BUCKET_STR_STRUCT

#include <std/str.h>
#include <analyzer/types/Struct.h>
struct HashMapBucket_str_Struct;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Struct {
    struct str key;
    struct Struct value;
    struct HashMapBucket_str_Struct* next;
};

#endif
