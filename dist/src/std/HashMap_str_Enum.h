#ifndef PAVE_HASH_MAP_STR_ENUM
#define PAVE_HASH_MAP_STR_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Enum;
struct HashMapBucket_str_Enum;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Enum {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Enum** buckets;
    struct HashMapBucket_str_Enum* data;
    uintptr_t capacity;
    uintptr_t length;
};

struct HashMap_str_Enum;
struct str;
struct Enum;
struct Enum;
#include <std/trait_Allocator.h>
#include <std/HashMap_str_Enum.h>
#include <std/str.h>
#include <analyzer/types/Enum.h>
#include <std/HashMapIter_str_Enum.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Enum HashMap_str_Enum__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Enum__resize(struct HashMap_str_Enum* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Enum* HashMap_str_Enum__find(struct HashMap_str_Enum* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Enum* HashMap_str_Enum__insert(struct HashMap_str_Enum* self, struct str key, struct Enum value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_Enum__remove(struct HashMap_str_Enum* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_Enum__release(struct HashMap_str_Enum* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Enum__fill_buckets(struct HashMap_str_Enum* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_Enum HashMap_str_Enum__clone(struct HashMap_str_Enum* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_Enum HashMap_str_Enum__iter(struct HashMap_str_Enum* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_Enum__clear(struct HashMap_str_Enum* self);

#endif
