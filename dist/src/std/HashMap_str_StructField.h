#ifndef PAVE_HASH_MAP_STR_STRUCT_FIELD
#define PAVE_HASH_MAP_STR_STRUCT_FIELD

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_StructField;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_StructField {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_StructField** buckets;
    struct HashMapBucket_str_StructField* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_StructField.h>
#include <std/str.h>
#include <analyzer/types/StructField.h>
#include <std/HashMapIter_str_StructField.h>
struct HashMap_str_StructField;
struct str;
struct StructField;
struct HashMapBucket_str_StructField;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_StructField HashMap_str_StructField__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_StructField HashMap_str_StructField__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_StructField__resize(struct HashMap_str_StructField* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct StructField* HashMap_str_StructField__find(struct HashMap_str_StructField* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct StructField* HashMap_str_StructField__insert(struct HashMap_str_StructField* self, struct str key, struct StructField value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_StructField__remove(struct HashMap_str_StructField* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_StructField__release(struct HashMap_str_StructField* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_StructField__fill_buckets(struct HashMap_str_StructField* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_StructField HashMap_str_StructField__clone(struct HashMap_str_StructField* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_StructField HashMap_str_StructField__iter(struct HashMap_str_StructField* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_StructField__clear(struct HashMap_str_StructField* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_StructField* HashMap_str_StructField__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct StructField* HashMap_str_StructField__Map_str_StructField__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct StructField* HashMap_str_StructField__Map_str_StructField__insert(void* __self, struct str key, struct StructField value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_StructField__Map_str_StructField__remove(void* __self, struct str* key);

extern struct trait_Map_str_StructFieldVTable HASH_MAP_STR_STRUCT_FIELD__VTABLE__MAP;

#endif
