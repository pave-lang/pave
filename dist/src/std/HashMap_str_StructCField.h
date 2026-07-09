#ifndef PAVE_HASH_MAP_STR_STRUCT_CFIELD
#define PAVE_HASH_MAP_STR_STRUCT_CFIELD

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_StructCField;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_StructCField {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_StructCField** buckets;
    struct HashMapBucket_str_StructCField* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_StructCField.h>
#include <std/str.h>
#include <analyzer/c/StructCField.h>
#include <std/HashMapIter_str_StructCField.h>
struct HashMap_str_StructCField;
struct str;
struct StructCField;
struct HashMapBucket_str_StructCField;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_StructCField HashMap_str_StructCField__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_StructCField HashMap_str_StructCField__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_StructCField__resize(struct HashMap_str_StructCField* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct StructCField* HashMap_str_StructCField__find(struct HashMap_str_StructCField* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct StructCField* HashMap_str_StructCField__insert(struct HashMap_str_StructCField* self, struct str key, struct StructCField value);

#line 107 "src/std/HashMap.pv"
bool HashMap_str_StructCField__remove(struct HashMap_str_StructCField* self, struct str* key);

#line 131 "src/std/HashMap.pv"
void HashMap_str_StructCField__release(struct HashMap_str_StructCField* self);

#line 140 "src/std/HashMap.pv"
void HashMap_str_StructCField__fill_buckets(struct HashMap_str_StructCField* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_str_StructCField HashMap_str_StructCField__clone(struct HashMap_str_StructCField* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_StructCField HashMap_str_StructCField__iter(struct HashMap_str_StructCField* self);

#line 182 "src/std/HashMap.pv"
void HashMap_str_StructCField__clear(struct HashMap_str_StructCField* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_StructCField* HashMap_str_StructCField__Index__index(void* __self);

#line 197 "src/std/HashMap.pv"
struct StructCField* HashMap_str_StructCField__Map_str_StructCField__find(void* __self, struct str* key);

#line 214 "src/std/HashMap.pv"
struct StructCField* HashMap_str_StructCField__Map_str_StructCField__insert(void* __self, struct str key, struct StructCField value);

#line 244 "src/std/HashMap.pv"
bool HashMap_str_StructCField__Map_str_StructCField__remove(void* __self, struct str* key);

extern struct trait_Map_str_StructCFieldVTable HASH_MAP_STR_STRUCT_CFIELD__VTABLE__MAP;

#endif
