#ifndef PAVE_HASH_MAP_STR_ARRAY_INLAY_HINT
#define PAVE_HASH_MAP_STR_ARRAY_INLAY_HINT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_InlayHint;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_InlayHint** buckets;
    struct HashMapBucket_str_Array_InlayHint* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <std/Array_InlayHint.h>
#include <std/HashMapIter_str_Array_InlayHint.h>
#include <std/trait_Map_str_Array_InlayHint.h>
struct str;
struct Array_InlayHint;
struct HashMapBucket_str_Array_InlayHint;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint HashMap_str_Array_InlayHint__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint HashMap_str_Array_InlayHint__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__resize(struct HashMap_str_Array_InlayHint* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Array_InlayHint* HashMap_str_Array_InlayHint__find(struct HashMap_str_Array_InlayHint* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Array_InlayHint* HashMap_str_Array_InlayHint__insert(struct HashMap_str_Array_InlayHint* self, struct str key, struct Array_InlayHint value);

#line 112 "src/std/HashMap.pv"
bool HashMap_str_Array_InlayHint__remove(struct HashMap_str_Array_InlayHint* self, struct str* key);

#line 136 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__release(struct HashMap_str_Array_InlayHint* self);

#line 145 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__fill_buckets(struct HashMap_str_Array_InlayHint* self);

#line 166 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint HashMap_str_Array_InlayHint__clone(struct HashMap_str_Array_InlayHint* self, struct trait_Allocator allocator);

#line 180 "src/std/HashMap.pv"
struct HashMapIter_str_Array_InlayHint HashMap_str_Array_InlayHint__iter(struct HashMap_str_Array_InlayHint* self);

#line 187 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__clear(struct HashMap_str_Array_InlayHint* self);

#line 196 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_InlayHint* HashMap_str_Array_InlayHint__Index__index(void* __self);

#line 202 "src/std/HashMap.pv"
struct Array_InlayHint* HashMap_str_Array_InlayHint__Map_str_Array_InlayHint__find(void* __self, struct str* key);

#line 219 "src/std/HashMap.pv"
struct Array_InlayHint* HashMap_str_Array_InlayHint__Map_str_Array_InlayHint__insert(void* __self, struct str key, struct Array_InlayHint value);

#line 253 "src/std/HashMap.pv"
bool HashMap_str_Array_InlayHint__Map_str_Array_InlayHint__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_InlayHintVTable HASH_MAP_STR_ARRAY_INLAY_HINT__VTABLE__MAP;

#endif
