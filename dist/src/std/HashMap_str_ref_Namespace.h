#ifndef PAVE_HASH_MAP_STR_REF_NAMESPACE
#define PAVE_HASH_MAP_STR_REF_NAMESPACE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Namespace;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Namespace** buckets;
    struct HashMapBucket_str_ref_Namespace* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Namespace.h>
struct HashMap_str_ref_Namespace;
struct str;
struct Namespace;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__resize(struct HashMap_str_ref_Namespace* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__find(struct HashMap_str_ref_Namespace* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__insert(struct HashMap_str_ref_Namespace* self, struct str key, struct Namespace* value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_ref_Namespace__remove(struct HashMap_str_ref_Namespace* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__release(struct HashMap_str_ref_Namespace* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__fill_buckets(struct HashMap_str_ref_Namespace* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__clone(struct HashMap_str_ref_Namespace* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Namespace HashMap_str_ref_Namespace__iter(struct HashMap_str_ref_Namespace* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__clear(struct HashMap_str_ref_Namespace* self);

#endif
