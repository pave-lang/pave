#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_MODULE
#define PAVE_HASH_MAP_BUCKET_STR_REF_MODULE

#include <stdio.h>
#include <string.h>

#include <std/str.h>
struct Module;
struct HashMapBucket_str_ref_Module;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Module {
    struct str key;
    struct Module* value;
    struct HashMapBucket_str_ref_Module* next;
};

#endif
