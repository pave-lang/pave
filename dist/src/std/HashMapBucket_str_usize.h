#ifndef PAVE_HASH_MAP_BUCKET_STR_USIZE
#define PAVE_HASH_MAP_BUCKET_STR_USIZE

#include <stdint.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_usize;
#include <std/str.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_usize {
    struct str key;
    uintptr_t value;
    struct HashMapBucket_str_usize* next;
};

#endif
