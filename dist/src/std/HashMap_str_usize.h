#ifndef PAVE_HASH_MAP_STR_USIZE
#define PAVE_HASH_MAP_STR_USIZE

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_usize;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_usize {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_usize** buckets;
    struct HashMapBucket_str_usize* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <std/HashMapIter_str_usize.h>
struct HashMap_str_usize;
struct str;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_usize HashMap_str_usize__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_usize__resize(struct HashMap_str_usize* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
uintptr_t* HashMap_str_usize__find(struct HashMap_str_usize* self, struct str* key);

#line 70 "src/std/HashMap.pv"
uintptr_t* HashMap_str_usize__insert(struct HashMap_str_usize* self, struct str key, uintptr_t value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_usize__remove(struct HashMap_str_usize* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_usize__release(struct HashMap_str_usize* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_usize__fill_buckets(struct HashMap_str_usize* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_usize HashMap_str_usize__clone(struct HashMap_str_usize* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_usize HashMap_str_usize__iter(struct HashMap_str_usize* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_usize__clear(struct HashMap_str_usize* self);

#endif
