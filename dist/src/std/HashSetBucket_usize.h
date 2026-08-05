#ifndef PAVE_HASH_SET_BUCKET_USIZE
#define PAVE_HASH_SET_BUCKET_USIZE

#include <stdint.h>


#line 4 "src/std/HashSet.pv"
struct HashSetBucket_usize {
    uintptr_t value;
    struct HashSetBucket_usize* next;
};

#endif
