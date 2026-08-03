#ifndef PAVE_HASH_MAP_STR_REF_TOKEN
#define PAVE_HASH_MAP_STR_REF_TOKEN

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Token;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_ref_Token {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Token** buckets;
    struct HashMapBucket_str_ref_Token* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Token.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Token.h>
#include <std/trait_Map_str_ref_Token.h>
struct HashMap_str_ref_Token;
struct str;
struct Token;
struct HashMapBucket_str_ref_Token;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_ref_Token HashMap_str_ref_Token__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_ref_Token HashMap_str_ref_Token__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_ref_Token__resize(struct HashMap_str_ref_Token* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct Token** HashMap_str_ref_Token__find(struct HashMap_str_ref_Token* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct Token** HashMap_str_ref_Token__insert(struct HashMap_str_ref_Token* self, struct str key, struct Token* value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_ref_Token__remove(struct HashMap_str_ref_Token* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_ref_Token__release(struct HashMap_str_ref_Token* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_ref_Token__fill_buckets(struct HashMap_str_ref_Token* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_ref_Token HashMap_str_ref_Token__clone(struct HashMap_str_ref_Token* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Token HashMap_str_ref_Token__iter(struct HashMap_str_ref_Token* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_ref_Token__clear(struct HashMap_str_ref_Token* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Token* HashMap_str_ref_Token__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct Token** HashMap_str_ref_Token__Map_str_ref_Token__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct Token** HashMap_str_ref_Token__Map_str_ref_Token__insert(void* __self, struct str key, struct Token* value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_ref_Token__Map_str_ref_Token__remove(void* __self, struct str* key);

extern struct trait_Map_str_ref_TokenVTable HASH_MAP_STR_REF_TOKEN__VTABLE__MAP;

#endif
