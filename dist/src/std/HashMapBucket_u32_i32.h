#ifndef PAVE_HASH_MAP_BUCKET_U32_I32
#define PAVE_HASH_MAP_BUCKET_U32_I32

#include <stdint.h>


#line 5 "src/std/HashMap.pv"
struct HashMapBucket_u32_i32 {
    uint32_t key;
    int32_t value;
    struct HashMapBucket_u32_i32* next;
};

#endif
