#ifndef PAVE_HASH_MAP_STR_TYPE
#define PAVE_HASH_MAP_STR_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Type;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Type {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Type** buckets;
    struct HashMapBucket_str_Type* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <std/HashMapIter_str_Type.h>
struct HashMap_str_Type;
struct str;
struct Type;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Type HashMap_str_Type__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Type__resize(struct HashMap_str_Type* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Type* HashMap_str_Type__find(struct HashMap_str_Type* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Type* HashMap_str_Type__insert(struct HashMap_str_Type* self, struct str key, struct Type value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_Type__remove(struct HashMap_str_Type* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_Type__release(struct HashMap_str_Type* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Type__fill_buckets(struct HashMap_str_Type* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_Type HashMap_str_Type__clone(struct HashMap_str_Type* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_Type HashMap_str_Type__iter(struct HashMap_str_Type* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_Type__clear(struct HashMap_str_Type* self);

#endif
