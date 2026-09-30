#ifndef PAVE_HASH_MAP_STR_ENUM_VARIANT
#define PAVE_HASH_MAP_STR_ENUM_VARIANT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_EnumVariant;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_EnumVariant** buckets;
    struct HashMapBucket_str_EnumVariant* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <analyzer/types/EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <std/trait_Map_str_EnumVariant.h>
struct str;
struct EnumVariant;
struct HashMapBucket_str_EnumVariant;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant HashMap_str_EnumVariant__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant HashMap_str_EnumVariant__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__resize(struct HashMap_str_EnumVariant* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct EnumVariant* HashMap_str_EnumVariant__find(struct HashMap_str_EnumVariant* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct EnumVariant* HashMap_str_EnumVariant__insert(struct HashMap_str_EnumVariant* self, struct str key, struct EnumVariant value);

#line 112 "src/std/HashMap.pv"
bool HashMap_str_EnumVariant__remove(struct HashMap_str_EnumVariant* self, struct str* key);

#line 136 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__release(struct HashMap_str_EnumVariant* self);

#line 145 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__fill_buckets(struct HashMap_str_EnumVariant* self);

#line 166 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant HashMap_str_EnumVariant__clone(struct HashMap_str_EnumVariant* self, struct trait_Allocator allocator);

#line 180 "src/std/HashMap.pv"
struct HashMapIter_str_EnumVariant HashMap_str_EnumVariant__iter(struct HashMap_str_EnumVariant* self);

#line 187 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__clear(struct HashMap_str_EnumVariant* self);

#line 196 "src/std/HashMap.pv"
struct HashMapBucket_str_EnumVariant* HashMap_str_EnumVariant__Index__index(void* __self);

#line 202 "src/std/HashMap.pv"
struct EnumVariant* HashMap_str_EnumVariant__Map_str_EnumVariant__find(void* __self, struct str* key);

#line 219 "src/std/HashMap.pv"
struct EnumVariant* HashMap_str_EnumVariant__Map_str_EnumVariant__insert(void* __self, struct str key, struct EnumVariant value);

#line 253 "src/std/HashMap.pv"
bool HashMap_str_EnumVariant__Map_str_EnumVariant__remove(void* __self, struct str* key);

extern struct trait_Map_str_EnumVariantVTable HASH_MAP_STR_ENUM_VARIANT__VTABLE__MAP;

#endif
