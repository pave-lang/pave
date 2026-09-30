#ifndef PAVE_HASH_SET_STR
#define PAVE_HASH_SET_STR

#include <stdint.h>
#include <stdbool.h>

struct ArenaAllocator;
struct HashSetBucket_str;

#line 26 "src/std/HashSet.pv"
struct HashSet_str {
    struct ArenaAllocator* allocator;
    struct HashSetBucket_str** buckets;
    struct HashSetBucket_str* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/str.h>
#include <std/HashSetIter_str.h>
struct ArenaAllocator;
struct str;

#line 35 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__new(struct ArenaAllocator* allocator);

#line 50 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity);

#line 59 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value);

#line 75 "src/std/HashSet.pv"
bool HashSet_str__insert(struct HashSet_str* self, struct str value);

#line 104 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self);

#line 113 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self);

#line 135 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator);

#line 151 "src/std/HashSet.pv"
struct HashSetIter_str HashSet_str__iter(struct HashSet_str* self);

#endif
