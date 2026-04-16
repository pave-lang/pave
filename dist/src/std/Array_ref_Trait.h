#ifndef PAVE_ARRAY_REF_TRAIT
#define PAVE_ARRAY_REF_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Trait {
    struct trait_Allocator allocator;
    struct Trait** data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_ref_Trait.h>
#include <std/Iter_ref_ref_Trait.h>
struct Array_ref_Trait;
struct Trait;

#line 77 "src/std/Array.pv"
struct Array_ref_Trait Array_ref_Trait__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Trait Array_ref_Trait__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Trait Array_ref_Trait__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Trait__reserve(struct Array_ref_Trait* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Trait** Array_ref_Trait__get(struct Array_ref_Trait* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Trait__append(struct Array_ref_Trait* self, struct Trait* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Trait__prepend(struct Array_ref_Trait* self, struct Trait* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Trait__remove_back(struct Array_ref_Trait* self);

#line 154 "src/std/Array.pv"
struct Trait** Array_ref_Trait__back(struct Array_ref_Trait* self);

#line 160 "src/std/Array.pv"
void Array_ref_Trait__clear(struct Array_ref_Trait* self);

#line 165 "src/std/Array.pv"
void Array_ref_Trait__release(struct Array_ref_Trait* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Trait Array_ref_Trait__clone(struct Array_ref_Trait* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Trait Array_ref_Trait__iter(struct Array_ref_Trait* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Trait Array_ref_Trait__as_slice(struct Array_ref_Trait* self);

#endif
