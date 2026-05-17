#ifndef PAVE_HASH_MAP_STR_ARRAY_INLAY_HINT
#define PAVE_HASH_MAP_STR_ARRAY_INLAY_HINT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_InlayHint;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_InlayHint** buckets;
    struct HashMapBucket_str_Array_InlayHint* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/str.h>
#include <std/Array_InlayHint.h>
#include <std/HashMapIter_str_Array_InlayHint.h>
struct HashMap_str_Array_InlayHint;
struct str;
struct Array_InlayHint;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint HashMap_str_Array_InlayHint__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint HashMap_str_Array_InlayHint__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__resize(struct HashMap_str_Array_InlayHint* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Array_InlayHint* HashMap_str_Array_InlayHint__find(struct HashMap_str_Array_InlayHint* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Array_InlayHint* HashMap_str_Array_InlayHint__insert(struct HashMap_str_Array_InlayHint* self, struct str key, struct Array_InlayHint value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_Array_InlayHint__remove(struct HashMap_str_Array_InlayHint* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__release(struct HashMap_str_Array_InlayHint* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__fill_buckets(struct HashMap_str_Array_InlayHint* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_Array_InlayHint HashMap_str_Array_InlayHint__clone(struct HashMap_str_Array_InlayHint* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_Array_InlayHint HashMap_str_Array_InlayHint__iter(struct HashMap_str_Array_InlayHint* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_Array_InlayHint__clear(struct HashMap_str_Array_InlayHint* self);

#endif
