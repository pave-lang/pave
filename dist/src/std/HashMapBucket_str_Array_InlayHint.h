#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_INLAY_HINT
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_INLAY_HINT

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Array_InlayHint;
#include <std/str.h>
#include <std/Array_InlayHint.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_InlayHint {
    struct str key;
    struct Array_InlayHint value;
    struct HashMapBucket_str_Array_InlayHint* next;
};

#endif
