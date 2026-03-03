#ifndef PAVE_HASH_MAP_STR_STRUCT
#define PAVE_HASH_MAP_STR_STRUCT

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_Struct;
struct str;
struct Struct;
struct HashMapIter_str_Struct;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Struct {
    struct Allocator allocator;
    struct HashMapBucket_str_Struct** buckets;
    struct HashMapBucket_str_Struct* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Struct HashMap_str_Struct__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_Struct__resize(struct HashMap_str_Struct* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Struct* HashMap_str_Struct__find(struct HashMap_str_Struct* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Struct* HashMap_str_Struct__insert(struct HashMap_str_Struct* self, struct str key, struct Struct value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_Struct__remove(struct HashMap_str_Struct* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_Struct__release(struct HashMap_str_Struct* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_Struct__fill_buckets(struct HashMap_str_Struct* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_Struct HashMap_str_Struct__clone(struct HashMap_str_Struct* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_Struct HashMap_str_Struct__iter(struct HashMap_str_Struct* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_Struct__clear(struct HashMap_str_Struct* self);

#endif
