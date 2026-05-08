#ifndef PAVE_HASH_MAP_STR_REF_CONST_VARIABLE
#define PAVE_HASH_MAP_STR_REF_CONST_VARIABLE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_ConstVariable;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_ConstVariable {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_ConstVariable** buckets;
    struct HashMapBucket_str_ref_ConstVariable* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_ConstVariable.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_ConstVariable.h>
struct HashMap_str_ref_ConstVariable;
struct str;
struct ConstVariable;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_ConstVariable HashMap_str_ref_ConstVariable__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_ref_ConstVariable__resize(struct HashMap_str_ref_ConstVariable* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct ConstVariable** HashMap_str_ref_ConstVariable__find(struct HashMap_str_ref_ConstVariable* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct ConstVariable** HashMap_str_ref_ConstVariable__insert(struct HashMap_str_ref_ConstVariable* self, struct str key, struct ConstVariable* value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_ref_ConstVariable__remove(struct HashMap_str_ref_ConstVariable* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_ref_ConstVariable__release(struct HashMap_str_ref_ConstVariable* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_ref_ConstVariable__fill_buckets(struct HashMap_str_ref_ConstVariable* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_ref_ConstVariable HashMap_str_ref_ConstVariable__clone(struct HashMap_str_ref_ConstVariable* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_ref_ConstVariable HashMap_str_ref_ConstVariable__iter(struct HashMap_str_ref_ConstVariable* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_ref_ConstVariable__clear(struct HashMap_str_ref_ConstVariable* self);

#endif
