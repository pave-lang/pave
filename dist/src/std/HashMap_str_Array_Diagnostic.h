#ifndef PAVE_HASH_MAP_STR_ARRAY_DIAGNOSTIC
#define PAVE_HASH_MAP_STR_ARRAY_DIAGNOSTIC

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_Diagnostic;

#line 26 "src/std/HashMap.pv"
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
struct HashMap_str_Array_Diagnostic;
struct str;
struct Array_Diagnostic;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_Diagnostic HashMap_str_Array_Diagnostic__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__resize(struct HashMap_str_Array_Diagnostic* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Array_Diagnostic* HashMap_str_Array_Diagnostic__find(struct HashMap_str_Array_Diagnostic* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Array_Diagnostic* HashMap_str_Array_Diagnostic__insert(struct HashMap_str_Array_Diagnostic* self, struct str key, struct Array_Diagnostic value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_Array_Diagnostic__remove(struct HashMap_str_Array_Diagnostic* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__release(struct HashMap_str_Array_Diagnostic* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__fill_buckets(struct HashMap_str_Array_Diagnostic* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_Array_Diagnostic HashMap_str_Array_Diagnostic__clone(struct HashMap_str_Array_Diagnostic* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_Array_Diagnostic HashMap_str_Array_Diagnostic__iter(struct HashMap_str_Array_Diagnostic* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_Array_Diagnostic__clear(struct HashMap_str_Array_Diagnostic* self);

#endif
