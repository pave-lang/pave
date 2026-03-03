#ifndef PAVE_HASH_SET_STR
#define PAVE_HASH_SET_STR

#include <stdint.h>
#include <stdbool.h>

struct ArenaAllocator;
struct HashSetBucket_str;
struct str;

#include <stdio.h>
#include <string.h>

#line 9 "src/std/HashSet.pv"
struct HashSet_str {
    struct ArenaAllocator* allocator;
    struct HashSetBucket_str** buckets;
    struct HashSetBucket_str* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 18 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__new(struct ArenaAllocator* allocator);

#line 29 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity);

#line 38 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value);

#line 53 "src/std/HashSet.pv"
bool HashSet_str__insert(struct HashSet_str* self, struct str value);

#line 77 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self);

#line 86 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self);

#line 105 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator);

#endif
