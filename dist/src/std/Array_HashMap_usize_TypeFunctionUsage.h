#ifndef PAVE_ARRAY_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_ARRAY_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct HashMap_usize_TypeFunctionUsage;
struct TypeFunctionUsage;
struct ArrayIter_ref_HashMap_usize_TypeFunctionUsage;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_HashMap_usize_TypeFunctionUsage {
    struct Allocator allocator;
    struct HashMap_usize_TypeFunctionUsage* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_HashMap_usize_TypeFunctionUsage Array_HashMap_usize_TypeFunctionUsage__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_HashMap_usize_TypeFunctionUsage Array_HashMap_usize_TypeFunctionUsage__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_HashMap_usize_TypeFunctionUsage Array_HashMap_usize_TypeFunctionUsage__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_HashMap_usize_TypeFunctionUsage__reserve(struct Array_HashMap_usize_TypeFunctionUsage* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct HashMap_usize_TypeFunctionUsage* Array_HashMap_usize_TypeFunctionUsage__get(struct Array_HashMap_usize_TypeFunctionUsage* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_HashMap_usize_TypeFunctionUsage__append(struct Array_HashMap_usize_TypeFunctionUsage* self, struct HashMap_usize_TypeFunctionUsage value);

#line 125 "src/std/Array.pv"
uintptr_t Array_HashMap_usize_TypeFunctionUsage__prepend(struct Array_HashMap_usize_TypeFunctionUsage* self, struct HashMap_usize_TypeFunctionUsage value);

#line 143 "src/std/Array.pv"
bool Array_HashMap_usize_TypeFunctionUsage__remove_back(struct Array_HashMap_usize_TypeFunctionUsage* self);

#line 154 "src/std/Array.pv"
struct HashMap_usize_TypeFunctionUsage* Array_HashMap_usize_TypeFunctionUsage__back(struct Array_HashMap_usize_TypeFunctionUsage* self);

#line 160 "src/std/Array.pv"
void Array_HashMap_usize_TypeFunctionUsage__clear(struct Array_HashMap_usize_TypeFunctionUsage* self);

#line 165 "src/std/Array.pv"
void Array_HashMap_usize_TypeFunctionUsage__release(struct Array_HashMap_usize_TypeFunctionUsage* self);

#line 172 "src/std/Array.pv"
struct Array_HashMap_usize_TypeFunctionUsage Array_HashMap_usize_TypeFunctionUsage__clone(struct Array_HashMap_usize_TypeFunctionUsage* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_HashMap_usize_TypeFunctionUsage Array_HashMap_usize_TypeFunctionUsage__iter(struct Array_HashMap_usize_TypeFunctionUsage* self);

#line 189 "src/std/Array.pv"
struct slice_HashMap_usize_TypeFunctionUsage Array_HashMap_usize_TypeFunctionUsage__as_slice(struct Array_HashMap_usize_TypeFunctionUsage* self);

#endif
