#ifndef PAVE_HASH_MAP_STR_ARRAY_REF_STRUCT
#define PAVE_HASH_MAP_STR_ARRAY_REF_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_Array_ref_Struct;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Struct {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_Array_ref_Struct** buckets;
    struct HashMapBucket_str_Array_ref_Struct* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_Array_ref_Struct.h>
#include <std/str.h>
#include <std/Array_ref_Struct.h>
#include <std/HashMapIter_str_Array_ref_Struct.h>
struct HashMap_str_Array_ref_Struct;
struct str;
struct Array_ref_Struct;
struct HashMapBucket_str_Array_ref_Struct;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Struct HashMap_str_Array_ref_Struct__new(struct trait_Allocator allocator);

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Struct HashMap_str_Array_ref_Struct__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 53 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Struct__resize(struct HashMap_str_Array_ref_Struct* self, uintptr_t new_capacity);

#line 60 "src/std/HashMap.pv"
struct Array_ref_Struct* HashMap_str_Array_ref_Struct__find(struct HashMap_str_Array_ref_Struct* self, struct str* key);

#line 77 "src/std/HashMap.pv"
struct Array_ref_Struct* HashMap_str_Array_ref_Struct__insert(struct HashMap_str_Array_ref_Struct* self, struct str key, struct Array_ref_Struct value);

#line 107 "src/std/HashMap.pv"
bool HashMap_str_Array_ref_Struct__remove(struct HashMap_str_Array_ref_Struct* self, struct str* key);

#line 131 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Struct__release(struct HashMap_str_Array_ref_Struct* self);

#line 140 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Struct__fill_buckets(struct HashMap_str_Array_ref_Struct* self);

#line 161 "src/std/HashMap.pv"
struct HashMap_str_Array_ref_Struct HashMap_str_Array_ref_Struct__clone(struct HashMap_str_Array_ref_Struct* self, struct trait_Allocator allocator);

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_Array_ref_Struct HashMap_str_Array_ref_Struct__iter(struct HashMap_str_Array_ref_Struct* self);

#line 182 "src/std/HashMap.pv"
void HashMap_str_Array_ref_Struct__clear(struct HashMap_str_Array_ref_Struct* self);

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_ref_Struct* HashMap_str_Array_ref_Struct__Index__index(void* __self);


#endif
