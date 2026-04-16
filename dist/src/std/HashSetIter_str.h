#ifndef PAVE_HASH_SET_ITER_STR
#define PAVE_HASH_SET_ITER_STR

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashSetBucket_str;

#line 9 "src/std/HashSet.pv"
struct HashSetIter_str {
    struct HashSetBucket_str* iter;
    struct HashSetBucket_str* end;
};

struct HashSetIter_str;
struct str;

#line 15 "src/std/HashSet.pv"
bool HashSetIter_str__next(struct HashSetIter_str* self);

#line 20 "src/std/HashSet.pv"
struct str* HashSetIter_str__value(struct HashSetIter_str* self);

#endif
