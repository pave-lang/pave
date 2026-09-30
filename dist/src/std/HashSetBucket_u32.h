#ifndef PAVE_HASH_SET_BUCKET_U32
#define PAVE_HASH_SET_BUCKET_U32

#include <stdint.h>


#line 5 "src/std/HashSet.pv"
struct HashSetBucket_u32 {
    uint32_t value;
    struct HashSetBucket_u32* next;
};

#endif
