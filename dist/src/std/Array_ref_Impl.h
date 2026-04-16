#ifndef PAVE_ARRAY_REF_IMPL
#define PAVE_ARRAY_REF_IMPL

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Impl {
    struct trait_Allocator allocator;
    struct Impl** data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_ref_Impl;
struct Impl;
#include <std/trait_Allocator.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>

#line 77 "src/std/Array.pv"
struct Array_ref_Impl Array_ref_Impl__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Impl Array_ref_Impl__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Impl Array_ref_Impl__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Impl__reserve(struct Array_ref_Impl* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Impl** Array_ref_Impl__get(struct Array_ref_Impl* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Impl__append(struct Array_ref_Impl* self, struct Impl* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Impl__prepend(struct Array_ref_Impl* self, struct Impl* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Impl__remove_back(struct Array_ref_Impl* self);

#line 154 "src/std/Array.pv"
struct Impl** Array_ref_Impl__back(struct Array_ref_Impl* self);

#line 160 "src/std/Array.pv"
void Array_ref_Impl__clear(struct Array_ref_Impl* self);

#line 165 "src/std/Array.pv"
void Array_ref_Impl__release(struct Array_ref_Impl* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Impl Array_ref_Impl__clone(struct Array_ref_Impl* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Impl Array_ref_Impl__iter(struct Array_ref_Impl* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Impl Array_ref_Impl__as_slice(struct Array_ref_Impl* self);

#endif
