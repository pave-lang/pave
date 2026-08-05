#ifndef PAVE_HASH_MAP_STR_ENUM_CVALUE
#define PAVE_HASH_MAP_STR_ENUM_CVALUE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_EnumCValue;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_EnumCValue** buckets;
    struct HashMapBucket_str_EnumCValue* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMapIter_str_EnumCValue.h>
#include <std/trait_Map_str_EnumCValue.h>
struct str;
struct EnumCValue;
struct HashMapBucket_str_EnumCValue;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue HashMap_str_EnumCValue__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue HashMap_str_EnumCValue__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__resize(struct HashMap_str_EnumCValue* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct EnumCValue* HashMap_str_EnumCValue__find(struct HashMap_str_EnumCValue* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct EnumCValue* HashMap_str_EnumCValue__insert(struct HashMap_str_EnumCValue* self, struct str key, struct EnumCValue value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_EnumCValue__remove(struct HashMap_str_EnumCValue* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__release(struct HashMap_str_EnumCValue* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__fill_buckets(struct HashMap_str_EnumCValue* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue HashMap_str_EnumCValue__clone(struct HashMap_str_EnumCValue* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_EnumCValue HashMap_str_EnumCValue__iter(struct HashMap_str_EnumCValue* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__clear(struct HashMap_str_EnumCValue* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_EnumCValue* HashMap_str_EnumCValue__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct EnumCValue* HashMap_str_EnumCValue__Map_str_EnumCValue__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct EnumCValue* HashMap_str_EnumCValue__Map_str_EnumCValue__insert(void* __self, struct str key, struct EnumCValue value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_EnumCValue__Map_str_EnumCValue__remove(void* __self, struct str* key);

extern struct trait_Map_str_EnumCValueVTable HASH_MAP_STR_ENUM_CVALUE__VTABLE__MAP;

#endif
