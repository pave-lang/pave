#ifndef PAVE_ARRAY_TYPE
#define PAVE_ARRAY_TYPE

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct Type;
struct ArrayIter_ref_Type;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_Type {
    struct Allocator allocator;
    struct Type* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_Type Array_Type__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Type Array_Type__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Type Array_Type__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Type__reserve(struct Array_Type* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Type* Array_Type__get(struct Array_Type* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Type__append(struct Array_Type* self, struct Type value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Type__prepend(struct Array_Type* self, struct Type value);

#line 143 "src/std/Array.pv"
bool Array_Type__remove_back(struct Array_Type* self);

#line 154 "src/std/Array.pv"
struct Type* Array_Type__back(struct Array_Type* self);

#line 160 "src/std/Array.pv"
void Array_Type__clear(struct Array_Type* self);

#line 165 "src/std/Array.pv"
void Array_Type__release(struct Array_Type* self);

#line 172 "src/std/Array.pv"
struct Array_Type Array_Type__clone(struct Array_Type* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_Type Array_Type__iter(struct Array_Type* self);

#line 188 "src/std/Array.pv"
struct slice_Type Array_Type__as_slice(struct Array_Type* self);

#endif
