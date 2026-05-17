#ifndef PAVE_HASH_MAP_STR_STRUCT
#define PAVE_HASH_MAP_STR_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Struct;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Struct {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Struct** buckets;
    struct HashMapBucket_str_Struct* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Struct.h>
#include <std/str.h>
#include <analyzer/types/Struct.h>
#include <std/HashMapIter_str_Struct.h>
struct HashMap_str_Struct;
struct str;
struct Struct;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Struct HashMap_str_Struct__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Struct HashMap_str_Struct__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Struct__resize(struct HashMap_str_Struct* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Struct* HashMap_str_Struct__find(struct HashMap_str_Struct* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Struct* HashMap_str_Struct__insert(struct HashMap_str_Struct* self, struct str key, struct Struct value);

#line 105 "src/std/HashMap.pv"
bool HashMap_str_Struct__remove(struct HashMap_str_Struct* self, struct str* key);

#line 129 "src/std/HashMap.pv"
void HashMap_str_Struct__release(struct HashMap_str_Struct* self);

#line 138 "src/std/HashMap.pv"
void HashMap_str_Struct__fill_buckets(struct HashMap_str_Struct* self);

#line 156 "src/std/HashMap.pv"
struct HashMap_str_Struct HashMap_str_Struct__clone(struct HashMap_str_Struct* self, struct trait_Allocator allocator);

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_Struct HashMap_str_Struct__iter(struct HashMap_str_Struct* self);

#line 177 "src/std/HashMap.pv"
void HashMap_str_Struct__clear(struct HashMap_str_Struct* self);

#endif
