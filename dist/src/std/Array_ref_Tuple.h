#ifndef PAVE_ARRAY_REF_TUPLE
#define PAVE_ARRAY_REF_TUPLE

#include <std/trait_Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct Tuple;
struct Iter_ref_ref_Tuple;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Tuple {
    struct trait_Allocator allocator;
    struct Tuple** data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_ref_Tuple Array_ref_Tuple__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Tuple Array_ref_Tuple__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Tuple Array_ref_Tuple__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Tuple__reserve(struct Array_ref_Tuple* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Tuple** Array_ref_Tuple__get(struct Array_ref_Tuple* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Tuple__append(struct Array_ref_Tuple* self, struct Tuple* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Tuple__prepend(struct Array_ref_Tuple* self, struct Tuple* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Tuple__remove_back(struct Array_ref_Tuple* self);

#line 154 "src/std/Array.pv"
struct Tuple** Array_ref_Tuple__back(struct Array_ref_Tuple* self);

#line 160 "src/std/Array.pv"
void Array_ref_Tuple__clear(struct Array_ref_Tuple* self);

#line 165 "src/std/Array.pv"
void Array_ref_Tuple__release(struct Array_ref_Tuple* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Tuple Array_ref_Tuple__clone(struct Array_ref_Tuple* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Tuple Array_ref_Tuple__iter(struct Array_ref_Tuple* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Tuple Array_ref_Tuple__as_slice(struct Array_ref_Tuple* self);

#endif
