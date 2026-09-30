#ifndef PAVE_HASH_SET_ITER_STR
#define PAVE_HASH_SET_ITER_STR

#include <stdbool.h>

struct HashSetBucket_str;

#line 10 "src/std/HashSet.pv"
struct HashSetIter_str {
    struct HashSetBucket_str* iter;
    struct HashSetBucket_str* end;
};

struct str;

#line 16 "src/std/HashSet.pv"
bool HashSetIter_str__next(struct HashSetIter_str* self);

#line 21 "src/std/HashSet.pv"
struct str* HashSetIter_str__value(struct HashSetIter_str* self);

#endif
