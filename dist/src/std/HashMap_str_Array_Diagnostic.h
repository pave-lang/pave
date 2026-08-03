#ifndef PAVE_HASH_MAP_STR_ARRAY_DIAGNOSTIC
#define PAVE_HASH_MAP_STR_ARRAY_DIAGNOSTIC

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_Diagnostic;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_Array_Diagnostic {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_Diagnostic** buckets;
    struct HashMapBucket_str_Array_Diagnostic* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/str.h>
#include <std/Array_Diagnostic.h>
#include <std/HashMapIter_str_Array_Diagnostic.h>
#include <std/trait_Map_str_Array_Diagnostic.h>
struct HashMap_str_Array_Diagnostic;
struct str;
struct Array_Diagnostic;
struct HashMapBucket_str_Array_Diagnostic;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Array_Diagnostic HashMap_str_Array_Diagnostic__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Array_Diagnostic HashMap_str_Array_Diagnostic__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__resize(struct HashMap_str_Array_Diagnostic* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Array_Diagnostic* HashMap_str_Array_Diagnostic__find(struct HashMap_str_Array_Diagnostic* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Array_Diagnostic* HashMap_str_Array_Diagnostic__insert(struct HashMap_str_Array_Diagnostic* self, struct str key, struct Array_Diagnostic value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_Array_Diagnostic__remove(struct HashMap_str_Array_Diagnostic* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__release(struct HashMap_str_Array_Diagnostic* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__fill_buckets(struct HashMap_str_Array_Diagnostic* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_Array_Diagnostic HashMap_str_Array_Diagnostic__clone(struct HashMap_str_Array_Diagnostic* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_Array_Diagnostic HashMap_str_Array_Diagnostic__iter(struct HashMap_str_Array_Diagnostic* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__clear(struct HashMap_str_Array_Diagnostic* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_Diagnostic* HashMap_str_Array_Diagnostic__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Array_Diagnostic* HashMap_str_Array_Diagnostic__Map_str_Array_Diagnostic__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Array_Diagnostic* HashMap_str_Array_Diagnostic__Map_str_Array_Diagnostic__insert(void* __self, struct str key, struct Array_Diagnostic value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_Array_Diagnostic__Map_str_Array_Diagnostic__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_DiagnosticVTable HASH_MAP_STR_ARRAY_DIAGNOSTIC__VTABLE__MAP;

#endif
