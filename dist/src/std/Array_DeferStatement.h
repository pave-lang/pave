#ifndef PAVE_ARRAY_DEFER_STATEMENT
#define PAVE_ARRAY_DEFER_STATEMENT

#include <std/trait_Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct DeferStatement;
struct Iter_ref_DeferStatement;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_DeferStatement {
    struct trait_Allocator allocator;
    struct DeferStatement* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_DeferStatement Array_DeferStatement__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_DeferStatement Array_DeferStatement__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_DeferStatement Array_DeferStatement__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_DeferStatement__reserve(struct Array_DeferStatement* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct DeferStatement* Array_DeferStatement__get(struct Array_DeferStatement* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_DeferStatement__append(struct Array_DeferStatement* self, struct DeferStatement value);

#line 125 "src/std/Array.pv"
uintptr_t Array_DeferStatement__prepend(struct Array_DeferStatement* self, struct DeferStatement value);

#line 143 "src/std/Array.pv"
bool Array_DeferStatement__remove_back(struct Array_DeferStatement* self);

#line 154 "src/std/Array.pv"
struct DeferStatement* Array_DeferStatement__back(struct Array_DeferStatement* self);

#line 160 "src/std/Array.pv"
void Array_DeferStatement__clear(struct Array_DeferStatement* self);

#line 165 "src/std/Array.pv"
void Array_DeferStatement__release(struct Array_DeferStatement* self);

#line 172 "src/std/Array.pv"
struct Array_DeferStatement Array_DeferStatement__clone(struct Array_DeferStatement* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_DeferStatement Array_DeferStatement__iter(struct Array_DeferStatement* self);

#line 188 "src/std/Array.pv"
struct slice_DeferStatement Array_DeferStatement__as_slice(struct Array_DeferStatement* self);

#endif
