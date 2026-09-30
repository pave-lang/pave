#ifndef PAVE_HASH_SET_ITER_USIZE
#define PAVE_HASH_SET_ITER_USIZE

#include <stdbool.h>
#include <stdint.h>

struct HashSetBucket_usize;

#line 10 "src/std/HashSet.pv"
struct HashSetIter_usize {
    struct HashSetBucket_usize* iter;
    struct HashSetBucket_usize* end;
};


#line 16 "src/std/HashSet.pv"
bool HashSetIter_usize__next(struct HashSetIter_usize* self);

#line 21 "src/std/HashSet.pv"
uintptr_t* HashSetIter_usize__value(struct HashSetIter_usize* self);

#endif
