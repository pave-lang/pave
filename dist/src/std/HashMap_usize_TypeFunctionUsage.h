#ifndef PAVE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct HashMapBucket_usize_TypeFunctionUsage;

#line 27 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage {
    struct trait_Allocator allocator;
    struct HashMapBucket_usize_TypeFunctionUsage** buckets;
    struct HashMapBucket_usize_TypeFunctionUsage* data;
    uintptr_t capacity;
    uintptr_t length;
};

#include <std/trait_Allocator.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>
struct HashMap_usize_TypeFunctionUsage;
struct TypeFunctionUsage;
struct HashMapBucket_usize_TypeFunctionUsage;

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__new(struct trait_Allocator allocator);

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__with_capacity(struct trait_Allocator allocator, uintptr_t capacity);

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__resize(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t new_capacity);

#line 61 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__find(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key);

#line 78 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__insert(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t key, struct TypeFunctionUsage value);

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeFunctionUsage__remove(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key);

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__release(struct HashMap_usize_TypeFunctionUsage* self);

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__fill_buckets(struct HashMap_usize_TypeFunctionUsage* self);

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__clone(struct HashMap_usize_TypeFunctionUsage* self, struct trait_Allocator allocator);

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__iter(struct HashMap_usize_TypeFunctionUsage* self);

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__clear(struct HashMap_usize_TypeFunctionUsage* self);

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__Index__index(void* __self);

#line 198 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__find(void* __self, uintptr_t* key);

#line 215 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__insert(void* __self, uintptr_t key, struct TypeFunctionUsage value);

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__remove(void* __self, uintptr_t* key);

extern struct trait_Map_usize_TypeFunctionUsageVTable HASH_MAP_USIZE_TYPE_FUNCTION_USAGE__VTABLE__MAP;

#endif
