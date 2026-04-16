#ifndef PAVE_HASH_SET_BUCKET_STR
#define PAVE_HASH_SET_BUCKET_STR

#include <std/str.h>
struct HashSetBucket_str;

#line 4 "src/std/HashSet.pv"
struct HashSetBucket_str {
    struct str value;
    struct HashSetBucket_str* next;
};

#endif
