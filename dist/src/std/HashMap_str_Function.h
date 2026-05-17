#ifndef PAVE_HASH_MAP_STR_FUNCTION
#define PAVE_HASH_MAP_STR_FUNCTION

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Function;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Function {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Function** buckets;
    struct HashMapBucket_str_Function* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <std/HashMapIter_str_Function.h>
struct HashMap_str_Function;
struct str;
struct Function;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Function HashMap_str_Function__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Function HashMap_str_Function__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Function__resize(struct HashMap_str_Function* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Function* HashMap_str_Function__find(struct HashMap_str_Function* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Function* HashMap_str_Function__insert(struct HashMap_str_Function* self, struct str key, struct Function value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_Function__remove(struct HashMap_str_Function* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_Function__release(struct HashMap_str_Function* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_Function__fill_buckets(struct HashMap_str_Function* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_Function HashMap_str_Function__clone(struct HashMap_str_Function* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_Function HashMap_str_Function__iter(struct HashMap_str_Function* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_Function__clear(struct HashMap_str_Function* self);

#endif
