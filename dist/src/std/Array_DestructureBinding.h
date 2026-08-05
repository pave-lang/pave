#ifndef PAVE_ARRAY_DESTRUCTURE_BINDING
#define PAVE_ARRAY_DESTRUCTURE_BINDING

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct DestructureBinding;

#line 69 "src/std/Array.pv"
struct Array_DestructureBinding {
    struct trait_Allocator allocator;
    struct DestructureBinding* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <analyzer/statement/DestructureBinding.h>
#include <std/Iter_ref_DestructureBinding.h>
#include <slice_DestructureBinding.h>
struct DestructureBinding;

#line 77 "src/std/Array.pv"
struct Array_DestructureBinding Array_DestructureBinding__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_DestructureBinding Array_DestructureBinding__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_DestructureBinding Array_DestructureBinding__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_DestructureBinding__reserve(struct Array_DestructureBinding* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct DestructureBinding* Array_DestructureBinding__get(struct Array_DestructureBinding* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_DestructureBinding__append(struct Array_DestructureBinding* self, struct DestructureBinding value);

#line 125 "src/std/Array.pv"
uintptr_t Array_DestructureBinding__prepend(struct Array_DestructureBinding* self, struct DestructureBinding value);

#line 143 "src/std/Array.pv"
bool Array_DestructureBinding__remove_back(struct Array_DestructureBinding* self);

#line 154 "src/std/Array.pv"
struct DestructureBinding* Array_DestructureBinding__back(struct Array_DestructureBinding* self);

#line 160 "src/std/Array.pv"
void Array_DestructureBinding__clear(struct Array_DestructureBinding* self);

#line 165 "src/std/Array.pv"
void Array_DestructureBinding__release(struct Array_DestructureBinding* self);

#line 172 "src/std/Array.pv"
struct Array_DestructureBinding Array_DestructureBinding__clone(struct Array_DestructureBinding* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_DestructureBinding Array_DestructureBinding__iter(struct Array_DestructureBinding* self);

#line 188 "src/std/Array.pv"
struct slice_DestructureBinding Array_DestructureBinding__as_slice(struct Array_DestructureBinding* self);

#line 195 "src/std/Array.pv"
struct DestructureBinding* Array_DestructureBinding__Index__index(void* __self);


#endif
