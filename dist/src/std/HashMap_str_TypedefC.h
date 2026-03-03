#ifndef PAVE_HASH_MAP_STR_TYPEDEF_C
#define PAVE_HASH_MAP_STR_TYPEDEF_C

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_TypedefC;
struct str;
struct TypedefC;
struct HashMapIter_str_TypedefC;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_TypedefC {
    struct Allocator allocator;
    struct HashMapBucket_str_TypedefC** buckets;
    struct HashMapBucket_str_TypedefC* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_TypedefC__resize(struct HashMap_str_TypedefC* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__find(struct HashMap_str_TypedefC* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct TypedefC* HashMap_str_TypedefC__insert(struct HashMap_str_TypedefC* self, struct str key, struct TypedefC value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_TypedefC__remove(struct HashMap_str_TypedefC* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_TypedefC__release(struct HashMap_str_TypedefC* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_TypedefC__fill_buckets(struct HashMap_str_TypedefC* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_TypedefC HashMap_str_TypedefC__clone(struct HashMap_str_TypedefC* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_TypedefC HashMap_str_TypedefC__iter(struct HashMap_str_TypedefC* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_TypedefC__clear(struct HashMap_str_TypedefC* self);

#endif
