#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_NAMESPACE
#define PAVE_HASH_MAP_BUCKET_STR_REF_NAMESPACE

#include <stdio.h>
#include <string.h>

struct Namespace;
struct HashMapBucket_str_ref_Namespace;
#include <std/str.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Namespace {
    struct str key;
    struct Namespace* value;
    struct HashMapBucket_str_ref_Namespace* next;
};

#endif
