#ifndef PAVE_HASH_MAP_STR_PRIMITIVE
#define PAVE_HASH_MAP_STR_PRIMITIVE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Primitive;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Primitive {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Primitive** buckets;
    struct HashMapBucket_str_Primitive* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Primitive.h>
#include <std/str.h>
#include <analyzer/types/Primitive.h>
#include <std/HashMapIter_str_Primitive.h>
struct HashMap_str_Primitive;
struct str;
struct Primitive;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Primitive__resize(struct HashMap_str_Primitive* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__find(struct HashMap_str_Primitive* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__insert(struct HashMap_str_Primitive* self, struct str key, struct Primitive value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_Primitive__remove(struct HashMap_str_Primitive* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_Primitive__release(struct HashMap_str_Primitive* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_Primitive__fill_buckets(struct HashMap_str_Primitive* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__clone(struct HashMap_str_Primitive* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_Primitive HashMap_str_Primitive__iter(struct HashMap_str_Primitive* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_Primitive__clear(struct HashMap_str_Primitive* self);

#endif
