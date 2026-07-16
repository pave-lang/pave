#ifndef PAVE_HASH_MAP_STR_PRIMITIVE
#define PAVE_HASH_MAP_STR_PRIMITIVE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Primitive;

#line 27 "src/std/HashMap.pv"
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
struct HashMapBucket_str_Primitive;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Primitive__resize(struct HashMap_str_Primitive* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__find(struct HashMap_str_Primitive* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__insert(struct HashMap_str_Primitive* self, struct str key, struct Primitive value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_Primitive__remove(struct HashMap_str_Primitive* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_Primitive__release(struct HashMap_str_Primitive* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_Primitive__fill_buckets(struct HashMap_str_Primitive* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_Primitive HashMap_str_Primitive__clone(struct HashMap_str_Primitive* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_Primitive HashMap_str_Primitive__iter(struct HashMap_str_Primitive* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_Primitive__clear(struct HashMap_str_Primitive* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_Primitive* HashMap_str_Primitive__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__Map_str_Primitive__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Primitive* HashMap_str_Primitive__Map_str_Primitive__insert(void* __self, struct str key, struct Primitive value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_Primitive__Map_str_Primitive__remove(void* __self, struct str* key);

extern struct trait_Map_str_PrimitiveVTable HASH_MAP_STR_PRIMITIVE__VTABLE__MAP;

#endif
