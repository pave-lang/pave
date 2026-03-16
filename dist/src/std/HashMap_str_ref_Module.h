#ifndef PAVE_HASH_MAP_STR_REF_MODULE
#define PAVE_HASH_MAP_STR_REF_MODULE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_ref_Module;
struct str;
struct Module;
struct HashMapIter_str_ref_Module;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_ref_Module {
    struct Allocator allocator;
    struct HashMapBucket_str_ref_Module** buckets;
    struct HashMapBucket_str_ref_Module* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Module HashMap_str_ref_Module__new(struct Allocator allocator);

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
struct HashMap_str_ref_Module HashMap_str_ref_Module__clone(struct HashMap_str_ref_Module* self, struct Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Module HashMap_str_ref_Module__iter(struct HashMap_str_ref_Module* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_ref_Module__clear(struct HashMap_str_ref_Module* self);

#endif
