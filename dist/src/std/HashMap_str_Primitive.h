#ifndef PAVE_HASH_MAP_STR_PRIMITIVE
#define PAVE_HASH_MAP_STR_PRIMITIVE

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Primitive;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Primitive {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Primitive** buckets;
    struct HashMapBucket_str_Primitive* data;
    uintptr_t capacity;
    uintptr_t length;
};

struct HashMap_str_Primitive;
struct str;
struct Primitive;
struct Primitive;
#include <std/trait_Allocator.h>
#include <std/HashMap_str_Primitive.h>
#include <std/str.h>
#include <analyzer/types/Primitive.h>
#include <std/HashMapIter_str_Primitive.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Primitive__resize(struct HashMap_str_Primitive* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__find(struct HashMap_str_Primitive* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__insert(struct HashMap_str_Primitive* self, struct str key, struct Primitive value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_Primitive__remove(struct HashMap_str_Primitive* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_Primitive__release(struct HashMap_str_Primitive* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Primitive__fill_buckets(struct HashMap_str_Primitive* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__clone(struct HashMap_str_Primitive* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_Primitive HashMap_str_Primitive__iter(struct HashMap_str_Primitive* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_Primitive__clear(struct HashMap_str_Primitive* self);

#endif
