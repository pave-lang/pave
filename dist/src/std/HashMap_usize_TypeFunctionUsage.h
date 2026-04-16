#ifndef PAVE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_usize_TypeFunctionUsage;
#include <std/trait_Allocator.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeFunctionUsage** buckets;
    struct HashMapBucket_usize_TypeFunctionUsage* data;
    uintptr_t capacity;
    uintptr_t length;
};

struct HashMap_usize_TypeFunctionUsage;
struct TypeFunctionUsage;
struct TypeFunctionUsage;
#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__new(struct trait_Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__resize(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__find(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__insert(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t key, struct TypeFunctionUsage value);

#line 98 "src/std/HashMap.pv"
bool HashMap_usize_TypeFunctionUsage__remove(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key);

#line 122 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__release(struct HashMap_usize_TypeFunctionUsage* self);

#line 131 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__fill_buckets(struct HashMap_usize_TypeFunctionUsage* self);

#line 149 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__clone(struct HashMap_usize_TypeFunctionUsage* self, struct trait_Allocator allocator);

#line 163 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__iter(struct HashMap_usize_TypeFunctionUsage* self);

#line 170 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__clear(struct HashMap_usize_TypeFunctionUsage* self);

#endif
