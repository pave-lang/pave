#ifndef PAVE_HASH_MAP_STR_ARRAY_REF_TRAIT
#define PAVE_HASH_MAP_STR_ARRAY_REF_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_ref_Trait;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Trait {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_ref_Trait** buckets;
    struct HashMapBucket_str_Array_ref_Trait* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/Array_ref_Trait.h>
#include <std/HashMapIter_str_Array_ref_Trait.h>
#include <std/trait_Map_str_Array_ref_Trait.h>
struct str;
struct Array_ref_Trait;
struct HashMapBucket_str_Array_ref_Trait;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Trait HashMap_str_Array_ref_Trait__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Trait HashMap_str_Array_ref_Trait__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Trait__resize(struct HashMap_str_Array_ref_Trait* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Array_ref_Trait* HashMap_str_Array_ref_Trait__find(struct HashMap_str_Array_ref_Trait* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Array_ref_Trait* HashMap_str_Array_ref_Trait__insert(struct HashMap_str_Array_ref_Trait* self, struct str key, struct Array_ref_Trait value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_Array_ref_Trait__remove(struct HashMap_str_Array_ref_Trait* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Trait__release(struct HashMap_str_Array_ref_Trait* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Trait__fill_buckets(struct HashMap_str_Array_ref_Trait* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Trait HashMap_str_Array_ref_Trait__clone(struct HashMap_str_Array_ref_Trait* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_Array_ref_Trait HashMap_str_Array_ref_Trait__iter(struct HashMap_str_Array_ref_Trait* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Trait__clear(struct HashMap_str_Array_ref_Trait* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_ref_Trait* HashMap_str_Array_ref_Trait__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Array_ref_Trait* HashMap_str_Array_ref_Trait__Map_str_Array_ref_Trait__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Array_ref_Trait* HashMap_str_Array_ref_Trait__Map_str_Array_ref_Trait__insert(void* __self, struct str key, struct Array_ref_Trait value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_Array_ref_Trait__Map_str_Array_ref_Trait__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_ref_TraitVTable HASH_MAP_STR_ARRAY_REF_TRAIT__VTABLE__MAP;

#endif
