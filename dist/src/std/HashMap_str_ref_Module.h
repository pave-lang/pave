#ifndef PAVE_HASH_MAP_STR_REF_MODULE
#define PAVE_HASH_MAP_STR_REF_MODULE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_str_ref_Module;

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Module {
    struct trait_Allocator allocator;
    struct HashMapBucket_str_ref_Module** buckets;
    struct HashMapBucket_str_ref_Module* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/str.h>
#include <std/HashMapIter_str_ref_Module.h>
struct HashMap_str_ref_Module;
struct str;
struct Module;

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Module HashMap_str_ref_Module__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_ref_Module__resize(struct HashMap_str_ref_Module* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct Module** HashMap_str_ref_Module__find(struct HashMap_str_ref_Module* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct Module** HashMap_str_ref_Module__insert(struct HashMap_str_ref_Module* self, struct str key, struct Module* value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_ref_Module__remove(struct HashMap_str_ref_Module* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_ref_Module__release(struct HashMap_str_ref_Module* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_ref_Module__fill_buckets(struct HashMap_str_ref_Module* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_ref_Module HashMap_str_ref_Module__clone(struct HashMap_str_ref_Module* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Module HashMap_str_ref_Module__iter(struct HashMap_str_ref_Module* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_ref_Module__clear(struct HashMap_str_ref_Module* self);

#endif
