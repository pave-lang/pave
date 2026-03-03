#ifndef PAVE_HASH_MAP_STR_FUNCTION
#define PAVE_HASH_MAP_STR_FUNCTION

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_Function;
struct str;
struct Function;
struct HashMapIter_str_Function;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Function {
    struct Allocator allocator;
    struct HashMapBucket_str_Function** buckets;
    struct HashMapBucket_str_Function* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Function HashMap_str_Function__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Function__resize(struct HashMap_str_Function* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Function* HashMap_str_Function__find(struct HashMap_str_Function* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Function* HashMap_str_Function__insert(struct HashMap_str_Function* self, struct str key, struct Function value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_Function__remove(struct HashMap_str_Function* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_Function__release(struct HashMap_str_Function* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_Function__fill_buckets(struct HashMap_str_Function* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_Function HashMap_str_Function__clone(struct HashMap_str_Function* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_Function HashMap_str_Function__iter(struct HashMap_str_Function* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_Function__clear(struct HashMap_str_Function* self);

#endif
