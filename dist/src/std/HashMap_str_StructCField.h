#ifndef PAVE_HASH_MAP_STR_STRUCT_CFIELD
#define PAVE_HASH_MAP_STR_STRUCT_CFIELD

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_StructCField;
struct HashMapBucket_str_StructCField;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_StructCField {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_StructCField** buckets;
    struct HashMapBucket_str_StructCField* data;
    uintptr_t capacity;
    uintptr_t length;
};

struct HashMap_str_StructCField;
struct str;
struct StructCField;
struct StructCField;
#include <std/trait_Allocator.h>
#include <std/HashMap_str_StructCField.h>
#include <std/str.h>
#include <analyzer/c/StructCField.h>
#include <std/HashMapIter_str_StructCField.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_StructCField HashMap_str_StructCField__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_StructCField__resize(struct HashMap_str_StructCField* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct StructCField* HashMap_str_StructCField__find(struct HashMap_str_StructCField* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct StructCField* HashMap_str_StructCField__insert(struct HashMap_str_StructCField* self, struct str key, struct StructCField value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_StructCField__remove(struct HashMap_str_StructCField* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_StructCField__release(struct HashMap_str_StructCField* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_StructCField__fill_buckets(struct HashMap_str_StructCField* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_StructCField HashMap_str_StructCField__clone(struct HashMap_str_StructCField* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_StructCField HashMap_str_StructCField__iter(struct HashMap_str_StructCField* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_StructCField__clear(struct HashMap_str_StructCField* self);

#endif
