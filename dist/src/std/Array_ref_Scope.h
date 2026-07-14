#ifndef PAVE_ARRAY_REF_SCOPE
#define PAVE_ARRAY_REF_SCOPE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Scope {
    struct trait_Allocator allocator;
    struct Scope** data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_ref_Scope.h>
#include <std/Iter_ref_ref_Scope.h>
#include <slice_ref_Scope.h>
struct Array_ref_Scope;
struct Scope;

#line 77 "src/std/Array.pv"
struct Array_ref_Scope Array_ref_Scope__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Scope Array_ref_Scope__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Scope Array_ref_Scope__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Scope__reserve(struct Array_ref_Scope* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Scope** Array_ref_Scope__get(struct Array_ref_Scope* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Scope__append(struct Array_ref_Scope* self, struct Scope* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Scope__prepend(struct Array_ref_Scope* self, struct Scope* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Scope__remove_back(struct Array_ref_Scope* self);

#line 154 "src/std/Array.pv"
struct Scope** Array_ref_Scope__back(struct Array_ref_Scope* self);

#line 160 "src/std/Array.pv"
void Array_ref_Scope__clear(struct Array_ref_Scope* self);

#line 165 "src/std/Array.pv"
void Array_ref_Scope__release(struct Array_ref_Scope* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Scope Array_ref_Scope__clone(struct Array_ref_Scope* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Scope Array_ref_Scope__iter(struct Array_ref_Scope* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Scope Array_ref_Scope__as_slice(struct Array_ref_Scope* self);

#line 195 "src/std/Array.pv"
struct Scope** Array_ref_Scope__Index__index(void* __self);


#endif
