#ifndef PAVE_HASH_MAP_STR_REF_NAMESPACE
#define PAVE_HASH_MAP_STR_REF_NAMESPACE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_ref_Namespace;
struct str;
struct Namespace;
struct HashMapIter_str_ref_Namespace;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace {
    struct Allocator allocator;
    struct HashMapBucket_str_ref_Namespace** buckets;
    struct HashMapBucket_str_ref_Namespace* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__resize(struct HashMap_str_ref_Namespace* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__find(struct HashMap_str_ref_Namespace* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__insert(struct HashMap_str_ref_Namespace* self, struct str key, struct Namespace* value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_ref_Namespace__remove(struct HashMap_str_ref_Namespace* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__release(struct HashMap_str_ref_Namespace* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__fill_buckets(struct HashMap_str_ref_Namespace* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__clone(struct HashMap_str_ref_Namespace* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Namespace HashMap_str_ref_Namespace__iter(struct HashMap_str_ref_Namespace* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__clear(struct HashMap_str_ref_Namespace* self);

#endif
