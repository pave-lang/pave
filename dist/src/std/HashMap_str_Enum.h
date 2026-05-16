#ifndef PAVE_HASH_MAP_STR_ENUM
#define PAVE_HASH_MAP_STR_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Enum;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Enum {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Enum** buckets;
    struct HashMapBucket_str_Enum* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Enum.h>
#include <std/str.h>
#include <analyzer/types/Enum.h>
#include <std/HashMapIter_str_Enum.h>
struct HashMap_str_Enum;
struct str;
struct Enum;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Enum HashMap_str_Enum__new(struct trait_Allocator allocator);

#line 50 "src/std/HashMap.pv"
void HashMap_str_Enum__resize(struct HashMap_str_Enum* self, uintptr_t new_capacity);

#line 57 "src/std/HashMap.pv"
struct Enum* HashMap_str_Enum__find(struct HashMap_str_Enum* self, struct str* key);

#line 74 "src/std/HashMap.pv"
struct Enum* HashMap_str_Enum__insert(struct HashMap_str_Enum* self, struct str key, struct Enum value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_Enum__remove(struct HashMap_str_Enum* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_Enum__release(struct HashMap_str_Enum* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_Enum__fill_buckets(struct HashMap_str_Enum* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_Enum HashMap_str_Enum__clone(struct HashMap_str_Enum* self, struct trait_Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_Enum HashMap_str_Enum__iter(struct HashMap_str_Enum* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_Enum__clear(struct HashMap_str_Enum* self);

#endif
