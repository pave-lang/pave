#ifndef PAVE_HASH_MAP_STR_REF_IMPL_CONST
#define PAVE_HASH_MAP_STR_REF_IMPL_CONST

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_ImplConst;

#line 26 "src/std/HashMap.pv"
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
struct HashMap_str_ref_ImplConst;
struct str;
struct ImplConst;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_ImplConst HashMap_str_ref_ImplConst__new(struct trait_Allocator allocator);

#line 50 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__resize(struct HashMap_str_ref_ImplConst* self, uintptr_t new_capacity);

#line 57 "src/std/HashMap.pv"
struct ImplConst** HashMap_str_ref_ImplConst__find(struct HashMap_str_ref_ImplConst* self, struct str* key);

#line 74 "src/std/HashMap.pv"
struct ImplConst** HashMap_str_ref_ImplConst__insert(struct HashMap_str_ref_ImplConst* self, struct str key, struct ImplConst* value);

#line 102 "src/std/HashMap.pv"
bool HashMap_str_ref_ImplConst__remove(struct HashMap_str_ref_ImplConst* self, struct str* key);

#line 126 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__release(struct HashMap_str_ref_ImplConst* self);

#line 135 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__fill_buckets(struct HashMap_str_ref_ImplConst* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_str_ref_ImplConst HashMap_str_ref_ImplConst__clone(struct HashMap_str_ref_ImplConst* self, struct trait_Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_str_ref_ImplConst HashMap_str_ref_ImplConst__iter(struct HashMap_str_ref_ImplConst* self);

#line 174 "src/std/HashMap.pv"
void HashMap_str_ref_ImplConst__clear(struct HashMap_str_ref_ImplConst* self);

#endif
