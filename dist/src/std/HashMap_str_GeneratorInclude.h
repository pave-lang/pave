#ifndef PAVE_HASH_MAP_STR_GENERATOR_INCLUDE
#define PAVE_HASH_MAP_STR_GENERATOR_INCLUDE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_str_GeneratorInclude;
struct str;
struct GeneratorInclude;
struct HashMapIter_str_GeneratorInclude;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_str_GeneratorInclude {
    struct Allocator allocator;
    struct HashMapBucket_str_GeneratorInclude** buckets;
    struct HashMapBucket_str_GeneratorInclude* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_str_GeneratorInclude HashMap_str_GeneratorInclude__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_str_GeneratorInclude__resize(struct HashMap_str_GeneratorInclude* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct GeneratorInclude* HashMap_str_GeneratorInclude__find(struct HashMap_str_GeneratorInclude* self, struct str* key);

#line 70 "src/std/HashMap.pv"
struct GeneratorInclude* HashMap_str_GeneratorInclude__insert(struct HashMap_str_GeneratorInclude* self, struct str key, struct GeneratorInclude value);

#line 98 "src/std/HashMap.pv"
bool HashMap_str_GeneratorInclude__remove(struct HashMap_str_GeneratorInclude* self, struct str* key);

#line 122 "src/std/HashMap.pv"
void HashMap_str_GeneratorInclude__release(struct HashMap_str_GeneratorInclude* self);

#line 131 "src/std/HashMap.pv"
void HashMap_str_GeneratorInclude__fill_buckets(struct HashMap_str_GeneratorInclude* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_str_GeneratorInclude HashMap_str_GeneratorInclude__clone(struct HashMap_str_GeneratorInclude* self, struct Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_GeneratorInclude HashMap_str_GeneratorInclude__iter(struct HashMap_str_GeneratorInclude* self);

#line 170 "src/std/HashMap.pv"
void HashMap_str_GeneratorInclude__clear(struct HashMap_str_GeneratorInclude* self);

#endif
