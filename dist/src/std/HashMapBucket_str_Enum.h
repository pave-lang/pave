#ifndef PAVE_HASH_MAP_BUCKET_STR_ENUM
#define PAVE_HASH_MAP_BUCKET_STR_ENUM

#include <std/str.h>
#include <analyzer/Enum.h>

struct HashMapBucket_str_Enum;
struct str;
struct Enum;

#include <stdio.h>
#include <string.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Enum {
    struct str key;
    struct Enum value;
    struct HashMapBucket_str_Enum* next;
};

#endif
