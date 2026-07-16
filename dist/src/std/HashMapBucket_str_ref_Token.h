#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_TOKEN
#define PAVE_HASH_MAP_BUCKET_STR_REF_TOKEN

#include <std/str.h>
struct Token;
struct HashMapBucket_str_ref_Token;

#line 5 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Token {
    struct str key;
    struct Token* value;
    struct HashMapBucket_str_ref_Token* next;
};

#endif
