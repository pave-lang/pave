#ifndef PAVE_ARRAY_REF_NAMESPACE
#define PAVE_ARRAY_REF_NAMESPACE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Namespace {
    struct trait_Allocator allocator;
    struct Namespace** data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_ref_Namespace.h>
#include <std/Iter_ref_ref_Namespace.h>
struct Array_ref_Namespace;
struct Namespace;

#line 77 "src/std/Array.pv"
struct Array_ref_Namespace Array_ref_Namespace__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Namespace Array_ref_Namespace__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Namespace Array_ref_Namespace__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Namespace__reserve(struct Array_ref_Namespace* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Namespace** Array_ref_Namespace__get(struct Array_ref_Namespace* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Namespace__append(struct Array_ref_Namespace* self, struct Namespace* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Namespace__prepend(struct Array_ref_Namespace* self, struct Namespace* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Namespace__remove_back(struct Array_ref_Namespace* self);

#line 154 "src/std/Array.pv"
struct Namespace** Array_ref_Namespace__back(struct Array_ref_Namespace* self);

#line 160 "src/std/Array.pv"
void Array_ref_Namespace__clear(struct Array_ref_Namespace* self);

#line 165 "src/std/Array.pv"
void Array_ref_Namespace__release(struct Array_ref_Namespace* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Namespace Array_ref_Namespace__clone(struct Array_ref_Namespace* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Namespace Array_ref_Namespace__iter(struct Array_ref_Namespace* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Namespace Array_ref_Namespace__as_slice(struct Array_ref_Namespace* self);

#endif
