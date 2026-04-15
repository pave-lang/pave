#ifndef PAVE_HASH_SET_BUCKET_STR
#define PAVE_HASH_SET_BUCKET_STR

#include <stdio.h>
#include <string.h>

struct HashSetBucket_str;
#include <std/str.h>

#line 4 "src/std/HashSet.pv"
struct HashSetBucket_str {
    struct str value;
    struct HashSetBucket_str* next;
};

#endif
