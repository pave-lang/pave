#ifndef PAVE_HASH_MAP_STR_TYPEDEF_C
#define PAVE_HASH_MAP_STR_TYPEDEF_C

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_TypedefC;
struct HashMapBucket_str_TypedefC;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_TypedefC {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_TypedefC** buckets;
    struct HashMapBucket_str_TypedefC* data;
    uintptr_t capacity;
    uintptr_t length;
};
struct HashMap_str_TypedefC;
struct str;
struct TypedefC;
struct TypedefC;
#include <std/trait_Allocator.h>
#include <std/HashMap_str_TypedefC.h>
#include <std/str.h>
#include <analyzer/c/TypedefC.h>
#include <std/HashMapIter_str_TypedefC.h>


#line 35 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_TypedefC__resize(struct HashMap_str_TypedefC* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__find(struct HashMap_str_TypedefC* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__insert(struct HashMap_str_TypedefC* self, struct str key, struct TypedefC value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_TypedefC__remove(struct HashMap_str_TypedefC* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_TypedefC__release(struct HashMap_str_TypedefC* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_TypedefC__fill_buckets(struct HashMap_str_TypedefC* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__clone(struct HashMap_str_TypedefC* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_TypedefC HashMap_str_TypedefC__iter(struct HashMap_str_TypedefC* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_TypedefC__clear(struct HashMap_str_TypedefC* self);

#endif
