#ifndef PAVE_HASH_SET_STR
#define PAVE_HASH_SET_STR

#include <stdint.h>
#include <stdbool.h>

struct ArenaAllocator;
struct HashSetBucket_str;

#line 25 "src/std/HashSet.pv"
struct HashSet_str {
    struct ArenaAllocator* allocator;
    struct HashSetBucket_str** buckets;
    struct HashSetBucket_str* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/HashSet_str.h>
#include <std/str.h>
#include <std/HashSetIter_str.h>
struct ArenaAllocator;
struct HashSet_str;
struct str;

#line 34 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__new(struct ArenaAllocator* allocator);

#line 49 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity);

#line 58 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value);

#line 73 "src/std/HashSet.pv"
bool HashSet_str__insert(struct HashSet_str* self, struct str value);

#line 97 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self);

#line 106 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self);

#line 125 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator);

#line 141 "src/std/HashSet.pv"
struct HashSetIter_str HashSet_str__iter(struct HashSet_str* self);

#endif
