#ifndef PAVE_HASH_SET_ITER_U32
#define PAVE_HASH_SET_ITER_U32

#include <stdbool.h>
#include <stdint.h>

struct HashSetBucket_u32;

#line 10 "src/std/HashSet.pv"
struct HashSetIter_u32 {
    struct HashSetBucket_u32* iter;
    struct HashSetBucket_u32* end;
};


#line 16 "src/std/HashSet.pv"
bool HashSetIter_u32__next(struct HashSetIter_u32* self);

#line 21 "src/std/HashSet.pv"
uint32_t* HashSetIter_u32__value(struct HashSetIter_u32* self);

#endif
