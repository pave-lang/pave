#ifndef PAVE_HASH_MAP_STR_REF_NAMESPACE
#define PAVE_HASH_MAP_STR_REF_NAMESPACE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Namespace;

#line 27 "src/std/HashMap.pv"
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
#include <std/trait_Map_str_ref_Namespace.h>
struct HashMap_str_ref_Namespace;
struct str;
struct Namespace;
struct HashMapBucket_str_ref_Namespace;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__resize(struct HashMap_str_ref_Namespace* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__find(struct HashMap_str_ref_Namespace* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__insert(struct HashMap_str_ref_Namespace* self, struct str key, struct Namespace* value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_ref_Namespace__remove(struct HashMap_str_ref_Namespace* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__release(struct HashMap_str_ref_Namespace* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__fill_buckets(struct HashMap_str_ref_Namespace* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_ref_Namespace HashMap_str_ref_Namespace__clone(struct HashMap_str_ref_Namespace* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Namespace HashMap_str_ref_Namespace__iter(struct HashMap_str_ref_Namespace* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_ref_Namespace__clear(struct HashMap_str_ref_Namespace* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Namespace* HashMap_str_ref_Namespace__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__Map_str_ref_Namespace__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Namespace** HashMap_str_ref_Namespace__Map_str_ref_Namespace__insert(void* __self, struct str key, struct Namespace* value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_ref_Namespace__Map_str_ref_Namespace__remove(void* __self, struct str* key);

extern struct trait_Map_str_ref_NamespaceVTable HASH_MAP_STR_REF_NAMESPACE__VTABLE__MAP;

#endif
