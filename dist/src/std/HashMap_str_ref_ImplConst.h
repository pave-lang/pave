#ifndef PAVE_HASH_MAP_STR_REF_IMPL_CONST
#define PAVE_HASH_MAP_STR_REF_IMPL_CONST

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_ImplConst;

#line 27 "src/std/HashMap.pv"
struct HashMap_str_ref_ImplConst {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_ImplConst** buckets;
    struct HashMapBucket_str_ref_ImplConst* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_ImplConst.h>
#include <std/trait_Map_str_ref_ImplConst.h>
struct HashMap_str_ref_ImplConst;
struct str;
struct ImplConst;
struct HashMapBucket_str_ref_ImplConst;

#line 36 "src/std/HashMap.pv"
struct HashMap_str_ref_ImplConst HashMap_str_ref_ImplConst__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_str_ref_ImplConst HashMap_str_ref_ImplConst__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__resize(struct HashMap_str_ref_ImplConst* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct ImplConst** HashMap_str_ref_ImplConst__find(struct HashMap_str_ref_ImplConst* self, struct str* key);

#line 78 "src/std/HashMap.pv"
struct ImplConst** HashMap_str_ref_ImplConst__insert(struct HashMap_str_ref_ImplConst* self, struct str key, struct ImplConst* value);

#line 108 "src/std/HashMap.pv"
bool HashMap_str_ref_ImplConst__remove(struct HashMap_str_ref_ImplConst* self, struct str* key);

#line 132 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__release(struct HashMap_str_ref_ImplConst* self);

#line 141 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__fill_buckets(struct HashMap_str_ref_ImplConst* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_str_ref_ImplConst HashMap_str_ref_ImplConst__clone(struct HashMap_str_ref_ImplConst* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_str_ref_ImplConst HashMap_str_ref_ImplConst__iter(struct HashMap_str_ref_ImplConst* self);

#line 183 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__clear(struct HashMap_str_ref_ImplConst* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_ImplConst* HashMap_str_ref_ImplConst__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct ImplConst** HashMap_str_ref_ImplConst__Map_str_ref_ImplConst__find(void* __self, struct str* key);

#line 215 "src/std/HashMap.pv"
struct ImplConst** HashMap_str_ref_ImplConst__Map_str_ref_ImplConst__insert(void* __self, struct str key, struct ImplConst* value);

#line 245 "src/std/HashMap.pv"
bool HashMap_str_ref_ImplConst__Map_str_ref_ImplConst__remove(void* __self, struct str* key);

extern struct trait_Map_str_ref_ImplConstVTable HASH_MAP_STR_REF_IMPL_CONST__VTABLE__MAP;

#endif
