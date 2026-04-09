#ifndef PAVE_ARRAY_TYPE_IMPL
#define PAVE_ARRAY_TYPE_IMPL

#include <std/trait_Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct TypeImpl;
struct Iter_ref_TypeImpl;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_TypeImpl {
    struct trait_Allocator allocator;
    struct TypeImpl* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_TypeImpl Array_TypeImpl__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_TypeImpl Array_TypeImpl__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_TypeImpl Array_TypeImpl__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_TypeImpl__reserve(struct Array_TypeImpl* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct TypeImpl* Array_TypeImpl__get(struct Array_TypeImpl* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_TypeImpl__append(struct Array_TypeImpl* self, struct TypeImpl value);

#line 125 "src/std/Array.pv"
uintptr_t Array_TypeImpl__prepend(struct Array_TypeImpl* self, struct TypeImpl value);

#line 143 "src/std/Array.pv"
bool Array_TypeImpl__remove_back(struct Array_TypeImpl* self);

#line 154 "src/std/Array.pv"
struct TypeImpl* Array_TypeImpl__back(struct Array_TypeImpl* self);

#line 160 "src/std/Array.pv"
void Array_TypeImpl__clear(struct Array_TypeImpl* self);

#line 165 "src/std/Array.pv"
void Array_TypeImpl__release(struct Array_TypeImpl* self);

#line 172 "src/std/Array.pv"
struct Array_TypeImpl Array_TypeImpl__clone(struct Array_TypeImpl* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_TypeImpl Array_TypeImpl__iter(struct Array_TypeImpl* self);

#line 188 "src/std/Array.pv"
struct slice_TypeImpl Array_TypeImpl__as_slice(struct Array_TypeImpl* self);

#endif
