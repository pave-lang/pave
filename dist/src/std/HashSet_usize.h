#ifndef PAVE_HASH_SET_USIZE
#define PAVE_HASH_SET_USIZE

#include <stdint.h>
#include <stdbool.h>

struct ArenaAllocator;
struct HashSetBucket_usize;

#line 26 "src/std/HashSet.pv"
struct HashSet_usize {
    struct ArenaAllocator* allocator;
    struct HashSetBucket_usize** buckets;
    struct HashSetBucket_usize* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/HashSetIter_usize.h>
struct ArenaAllocator;

#line 35 "src/std/HashSet.pv"
struct HashSet_usize HashSet_usize__new(struct ArenaAllocator* allocator);

#line 50 "src/std/HashSet.pv"
void HashSet_usize__resize(struct HashSet_usize* self, uintptr_t new_capacity);

#line 59 "src/std/HashSet.pv"
bool HashSet_usize__has(struct HashSet_usize* self, uintptr_t* value);

#line 75 "src/std/HashSet.pv"
bool HashSet_usize__insert(struct HashSet_usize* self, uintptr_t value);

#line 104 "src/std/HashSet.pv"
void HashSet_usize__release(struct HashSet_usize* self);

#line 113 "src/std/HashSet.pv"
void HashSet_usize__fill_buckets(struct HashSet_usize* self);

#line 135 "src/std/HashSet.pv"
struct HashSet_usize HashSet_usize__clone(struct HashSet_usize* self, struct ArenaAllocator* allocator);

#line 151 "src/std/HashSet.pv"
struct HashSetIter_usize HashSet_usize__iter(struct HashSet_usize* self);

#endif
