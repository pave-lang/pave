#ifndef PAVE_HASH_MAP_STR_TUPLE_REF_TRAIT_REF_TYPE
#define PAVE_HASH_MAP_STR_TUPLE_REF_TRAIT_REF_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_tuple_ref_Trait_ref_Type;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_tuple_ref_Trait_ref_Type {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_tuple_ref_Trait_ref_Type** buckets;
    struct HashMapBucket_str_tuple_ref_Trait_ref_Type* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/str.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMapIter_str_tuple_ref_Trait_ref_Type.h>
struct HashMap_str_tuple_ref_Trait_ref_Type;
struct str;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_tuple_ref_Trait_ref_Type HashMap_str_tuple_ref_Trait_ref_Type__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_tuple_ref_Trait_ref_Type HashMap_str_tuple_ref_Trait_ref_Type__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_tuple_ref_Trait_ref_Type__resize(struct HashMap_str_tuple_ref_Trait_ref_Type* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct tuple_ref_Trait_ref_Type* HashMap_str_tuple_ref_Trait_ref_Type__find(struct HashMap_str_tuple_ref_Trait_ref_Type* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct tuple_ref_Trait_ref_Type* HashMap_str_tuple_ref_Trait_ref_Type__insert(struct HashMap_str_tuple_ref_Trait_ref_Type* self, struct str key, struct tuple_ref_Trait_ref_Type value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_tuple_ref_Trait_ref_Type__remove(struct HashMap_str_tuple_ref_Trait_ref_Type* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_tuple_ref_Trait_ref_Type__release(struct HashMap_str_tuple_ref_Trait_ref_Type* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_tuple_ref_Trait_ref_Type__fill_buckets(struct HashMap_str_tuple_ref_Trait_ref_Type* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_tuple_ref_Trait_ref_Type HashMap_str_tuple_ref_Trait_ref_Type__clone(struct HashMap_str_tuple_ref_Trait_ref_Type* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_tuple_ref_Trait_ref_Type HashMap_str_tuple_ref_Trait_ref_Type__iter(struct HashMap_str_tuple_ref_Trait_ref_Type* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_tuple_ref_Trait_ref_Type__clear(struct HashMap_str_tuple_ref_Trait_ref_Type* self);

#endif
