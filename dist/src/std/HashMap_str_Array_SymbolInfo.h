#ifndef PAVE_HASH_MAP_STR_ARRAY_SYMBOL_INFO
#define PAVE_HASH_MAP_STR_ARRAY_SYMBOL_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_SymbolInfo;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Array_SymbolInfo {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_SymbolInfo** buckets;
    struct HashMapBucket_str_Array_SymbolInfo* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Array_SymbolInfo.h>
#include <std/str.h>
#include <std/Array_SymbolInfo.h>
#include <std/HashMapIter_str_Array_SymbolInfo.h>
struct HashMap_str_Array_SymbolInfo;
struct str;
struct Array_SymbolInfo;
struct HashMapBucket_str_Array_SymbolInfo;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_SymbolInfo HashMap_str_Array_SymbolInfo__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Array_SymbolInfo HashMap_str_Array_SymbolInfo__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Array_SymbolInfo__resize(struct HashMap_str_Array_SymbolInfo* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Array_SymbolInfo* HashMap_str_Array_SymbolInfo__find(struct HashMap_str_Array_SymbolInfo* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Array_SymbolInfo* HashMap_str_Array_SymbolInfo__insert(struct HashMap_str_Array_SymbolInfo* self, struct str key, struct Array_SymbolInfo value);

#line 107 "src/std/HashMap.pv"
bool HashMap_str_Array_SymbolInfo__remove(struct HashMap_str_Array_SymbolInfo* self, struct str* key);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Array_SymbolInfo__release(struct HashMap_str_Array_SymbolInfo* self);

#line 140 "src/std/HashMap.pv"
void HashMap_str_Array_SymbolInfo__fill_buckets(struct HashMap_str_Array_SymbolInfo* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_str_Array_SymbolInfo HashMap_str_Array_SymbolInfo__clone(struct HashMap_str_Array_SymbolInfo* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_Array_SymbolInfo HashMap_str_Array_SymbolInfo__iter(struct HashMap_str_Array_SymbolInfo* self);

#line 182 "src/std/HashMap.pv"
void HashMap_str_Array_SymbolInfo__clear(struct HashMap_str_Array_SymbolInfo* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_SymbolInfo* HashMap_str_Array_SymbolInfo__Index__index(void* __self);

#line 197 "src/std/HashMap.pv"
struct Array_SymbolInfo* HashMap_str_Array_SymbolInfo__Map_str_Array_SymbolInfo__find(void* __self, struct str* key);

#line 214 "src/std/HashMap.pv"
struct Array_SymbolInfo* HashMap_str_Array_SymbolInfo__Map_str_Array_SymbolInfo__insert(void* __self, struct str key, struct Array_SymbolInfo value);

#line 244 "src/std/HashMap.pv"
bool HashMap_str_Array_SymbolInfo__Map_str_Array_SymbolInfo__remove(void* __self, struct str* key);

extern struct trait_Map_str_Array_SymbolInfoVTable HASH_MAP_STR_ARRAY_SYMBOL_INFO__VTABLE__MAP;

#endif
