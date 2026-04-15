#ifndef PAVE_HASH_MAP_STR_REF_TYPE
#define PAVE_HASH_MAP_STR_REF_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_ref_Type;
struct HashMapBucket_str_ref_Type;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Type {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Type** buckets;
    struct HashMapBucket_str_ref_Type* data;
    uintptr_t capacity;
    uintptr_t length;
};
struct HashMap_str_ref_Type;
struct str;
struct Type;
struct Type;
struct Type;
#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Type.h>


#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Type HashMap_str_ref_Type__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_ref_Type__resize(struct HashMap_str_ref_Type* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Type** HashMap_str_ref_Type__find(struct HashMap_str_ref_Type* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Type** HashMap_str_ref_Type__insert(struct HashMap_str_ref_Type* self, struct str key, struct Type* value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_ref_Type__remove(struct HashMap_str_ref_Type* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_ref_Type__release(struct HashMap_str_ref_Type* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_ref_Type__fill_buckets(struct HashMap_str_ref_Type* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_ref_Type HashMap_str_ref_Type__clone(struct HashMap_str_ref_Type* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Type HashMap_str_ref_Type__iter(struct HashMap_str_ref_Type* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_ref_Type__clear(struct HashMap_str_ref_Type* self);

#endif
