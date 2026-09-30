#ifndef PAVE_HASH_SET_U32
#define PAVE_HASH_SET_U32

#include <stdint.h>
#include <stdbool.h>

struct ArenaAllocator;
struct HashSetBucket_u32;

#line 26 "src/std/HashSet.pv"
struct HashSet_u32 {
    struct ArenaAllocator* allocator;
    struct HashSetBucket_u32** buckets;
    struct HashSetBucket_u32* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/HashSetIter_u32.h>
struct ArenaAllocator;

#line 35 "src/std/HashSet.pv"
struct HashSet_u32 HashSet_u32__new(struct ArenaAllocator* allocator);

#line 50 "src/std/HashSet.pv"
void HashSet_u32__resize(struct HashSet_u32* self, uintptr_t new_capacity);

#line 59 "src/std/HashSet.pv"
bool HashSet_u32__has(struct HashSet_u32* self, uint32_t* value);

#line 75 "src/std/HashSet.pv"
bool HashSet_u32__insert(struct HashSet_u32* self, uint32_t value);

#line 104 "src/std/HashSet.pv"
void HashSet_u32__release(struct HashSet_u32* self);

#line 113 "src/std/HashSet.pv"
void HashSet_u32__fill_buckets(struct HashSet_u32* self);

#line 135 "src/std/HashSet.pv"
struct HashSet_u32 HashSet_u32__clone(struct HashSet_u32* self, struct ArenaAllocator* allocator);

#line 151 "src/std/HashSet.pv"
struct HashSetIter_u32 HashSet_u32__iter(struct HashSet_u32* self);

#endif
