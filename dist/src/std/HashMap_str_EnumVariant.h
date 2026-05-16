#ifndef PAVE_HASH_MAP_STR_ENUM_VARIANT
#define PAVE_HASH_MAP_STR_ENUM_VARIANT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_EnumVariant;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_EnumVariant** buckets;
    struct HashMapBucket_str_EnumVariant* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/str.h>
#include <analyzer/types/EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
struct HashMap_str_EnumVariant;
struct str;
struct EnumVariant;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant HashMap_str_EnumVariant__new(struct trait_Allocator allocator);

#line 50 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__resize(struct HashMap_str_EnumVariant* self, uintptr_t new_capacity);

#line 57 "src/std/HashMap.pv"
struct EnumVariant* HashMap_str_EnumVariant__find(struct HashMap_str_EnumVariant* self, struct str* key);

#line 74 "src/std/HashMap.pv"
struct EnumVariant* HashMap_str_EnumVariant__insert(struct HashMap_str_EnumVariant* self, struct str key, struct EnumVariant value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_EnumVariant__remove(struct HashMap_str_EnumVariant* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__release(struct HashMap_str_EnumVariant* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__fill_buckets(struct HashMap_str_EnumVariant* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_EnumVariant HashMap_str_EnumVariant__clone(struct HashMap_str_EnumVariant* self, struct trait_Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_EnumVariant HashMap_str_EnumVariant__iter(struct HashMap_str_EnumVariant* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_EnumVariant__clear(struct HashMap_str_EnumVariant* self);

#endif
