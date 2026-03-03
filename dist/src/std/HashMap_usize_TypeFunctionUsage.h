#ifndef PAVE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMapBucket_usize_TypeFunctionUsage;
struct TypeFunctionUsage;
struct HashMapIter_usize_TypeFunctionUsage;

#include <stdio.h>
#include <string.h>

#line 26 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage {
    struct Allocator allocator;
    struct HashMapBucket_usize_TypeFunctionUsage** buckets;
    struct HashMapBucket_usize_TypeFunctionUsage* data;
    uintptr_t capacity;
    uintptr_t length;
};

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__new(struct Allocator allocator);

#line 46 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__resize(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t new_capacity);

#line 53 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__find(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key);

#line 70 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__insert(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t key, struct TypeFunctionUsage value);

#line 102 "src/std/HashMap.pv"
bool HashMap_usize_TypeFunctionUsage__remove(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key);

#line 126 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__release(struct HashMap_usize_TypeFunctionUsage* self);

#line 135 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__fill_buckets(struct HashMap_usize_TypeFunctionUsage* self);

#line 153 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__clone(struct HashMap_usize_TypeFunctionUsage* self, struct Allocator allocator);

#line 167 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__iter(struct HashMap_usize_TypeFunctionUsage* self);

#line 174 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__clear(struct HashMap_usize_TypeFunctionUsage* self);

#endif
