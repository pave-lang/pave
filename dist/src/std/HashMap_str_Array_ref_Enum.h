#ifndef PAVE_HASH_MAP_STR_ARRAY_REF_ENUM
#define PAVE_HASH_MAP_STR_ARRAY_REF_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_ref_Enum;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Enum {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_ref_Enum** buckets;
    struct HashMapBucket_str_Array_ref_Enum* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/Array_ref_Enum.h>
#include <std/HashMapIter_str_Array_ref_Enum.h>
#include <std/trait_Map_str_Array_ref_Enum.h>
struct str;
struct Array_ref_Enum;
struct HashMapBucket_str_Array_ref_Enum;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Enum HashMap_str_Array_ref_Enum__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Enum HashMap_str_Array_ref_Enum__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Enum__resize(struct HashMap_str_Array_ref_Enum* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Array_ref_Enum* HashMap_str_Array_ref_Enum__find(struct HashMap_str_Array_ref_Enum* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Array_ref_Enum* HashMap_str_Array_ref_Enum__insert(struct HashMap_str_Array_ref_Enum* self, struct str key, struct Array_ref_Enum value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_Array_ref_Enum__remove(struct HashMap_str_Array_ref_Enum* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Enum__release(struct HashMap_str_Array_ref_Enum* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Enum__fill_buckets(struct HashMap_str_Array_ref_Enum* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Enum HashMap_str_Array_ref_Enum__clone(struct HashMap_str_Array_ref_Enum* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_Array_ref_Enum HashMap_str_Array_ref_Enum__iter(struct HashMap_str_Array_ref_Enum* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Enum__clear(struct HashMap_str_Array_ref_Enum* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_ref_Enum* HashMap_str_Array_ref_Enum__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Array_ref_Enum* HashMap_str_Array_ref_Enum__Map_str_Array_ref_Enum__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Array_ref_Enum* HashMap_str_Array_ref_Enum__Map_str_Array_ref_Enum__insert(void* __self, struct str key, struct Array_ref_Enum value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_Array_ref_Enum__Map_str_Array_ref_Enum__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_ref_EnumVTable HASH_MAP_STR_ARRAY_REF_ENUM__VTABLE__MAP;

#endif
