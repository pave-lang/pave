#ifndef PAVE_HASH_MAP_STR_TYPEDEF_C
#define PAVE_HASH_MAP_STR_TYPEDEF_C

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_TypedefC;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_TypedefC {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_TypedefC** buckets;
    struct HashMapBucket_str_TypedefC* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_TypedefC.h>
#include <std/str.h>
#include <analyzer/c/TypedefC.h>
#include <std/HashMapIter_str_TypedefC.h>
#include <std/trait_Map_str_TypedefC.h>
struct HashMap_str_TypedefC;
struct str;
struct TypedefC;
struct HashMapBucket_str_TypedefC;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_TypedefC__resize(struct HashMap_str_TypedefC* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__find(struct HashMap_str_TypedefC* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__insert(struct HashMap_str_TypedefC* self, struct str key, struct TypedefC value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_TypedefC__remove(struct HashMap_str_TypedefC* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_TypedefC__release(struct HashMap_str_TypedefC* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_TypedefC__fill_buckets(struct HashMap_str_TypedefC* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__clone(struct HashMap_str_TypedefC* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_TypedefC HashMap_str_TypedefC__iter(struct HashMap_str_TypedefC* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_TypedefC__clear(struct HashMap_str_TypedefC* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_TypedefC* HashMap_str_TypedefC__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__Map_str_TypedefC__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__Map_str_TypedefC__insert(void* __self, struct str key, struct TypedefC value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_TypedefC__Map_str_TypedefC__remove(void* __self, struct str* key);

extern struct trait_Map_str_TypedefCVTable HASH_MAP_STR_TYPEDEF_C__VTABLE__MAP;

#endif
