#ifndef PAVE_HASH_MAP_STR_ENUM_CVALUE
#define PAVE_HASH_MAP_STR_ENUM_CVALUE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_EnumCValue;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_EnumCValue** buckets;
    struct HashMapBucket_str_EnumCValue* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_EnumCValue.h>
#include <std/str.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMapIter_str_EnumCValue.h>
struct HashMap_str_EnumCValue;
struct str;
struct EnumCValue;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue HashMap_str_EnumCValue__new(struct trait_Allocator allocator);

#line 50 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__resize(struct HashMap_str_EnumCValue* self, uintptr_t new_capacity);

#line 57 "src/std/HashMap.pv"
struct EnumCValue* HashMap_str_EnumCValue__find(struct HashMap_str_EnumCValue* self, struct str* key);

#line 74 "src/std/HashMap.pv"
struct EnumCValue* HashMap_str_EnumCValue__insert(struct HashMap_str_EnumCValue* self, struct str key, struct EnumCValue value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_EnumCValue__remove(struct HashMap_str_EnumCValue* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__release(struct HashMap_str_EnumCValue* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__fill_buckets(struct HashMap_str_EnumCValue* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_EnumCValue HashMap_str_EnumCValue__clone(struct HashMap_str_EnumCValue* self, struct trait_Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_EnumCValue HashMap_str_EnumCValue__iter(struct HashMap_str_EnumCValue* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_EnumCValue__clear(struct HashMap_str_EnumCValue* self);

#endif
