#ifndef PAVE_ARRAY_GENERIC
#define PAVE_ARRAY_GENERIC

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct Generic;

#line 69 "src/std/Array.pv"
struct Array_Generic {
    struct trait_Allocator allocator;
    struct Generic* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generic.h>
#include <std/Iter_ref_Generic.h>
struct Array_Generic;
struct Generic;

#line 77 "src/std/Array.pv"
struct Array_Generic Array_Generic__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Generic Array_Generic__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Generic Array_Generic__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Generic__reserve(struct Array_Generic* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Generic* Array_Generic__get(struct Array_Generic* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Generic__append(struct Array_Generic* self, struct Generic value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Generic__prepend(struct Array_Generic* self, struct Generic value);

#line 143 "src/std/Array.pv"
bool Array_Generic__remove_back(struct Array_Generic* self);

#line 154 "src/std/Array.pv"
struct Generic* Array_Generic__back(struct Array_Generic* self);

#line 160 "src/std/Array.pv"
void Array_Generic__clear(struct Array_Generic* self);

#line 165 "src/std/Array.pv"
void Array_Generic__release(struct Array_Generic* self);

#line 172 "src/std/Array.pv"
struct Array_Generic Array_Generic__clone(struct Array_Generic* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_Generic Array_Generic__iter(struct Array_Generic* self);

#line 188 "src/std/Array.pv"
struct slice_Generic Array_Generic__as_slice(struct Array_Generic* self);

#endif
