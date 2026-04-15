#ifndef PAVE_ARRAY_SCOPE
#define PAVE_ARRAY_SCOPE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Scope;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_Scope {
    struct trait_Allocator allocator;
    struct Scope* data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_Scope;
struct Scope;
struct Scope;
#include <std/trait_Allocator.h>
#include <std/Array_Scope.h>
#include <analyzer/Scope.h>
#include <std/Iter_ref_Scope.h>

#line 77 "src/std/Array.pv"
struct Array_Scope Array_Scope__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Scope Array_Scope__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Scope Array_Scope__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Scope__reserve(struct Array_Scope* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Scope* Array_Scope__get(struct Array_Scope* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Scope__append(struct Array_Scope* self, struct Scope value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Scope__prepend(struct Array_Scope* self, struct Scope value);

#line 143 "src/std/Array.pv"
bool Array_Scope__remove_back(struct Array_Scope* self);

#line 154 "src/std/Array.pv"
struct Scope* Array_Scope__back(struct Array_Scope* self);

#line 160 "src/std/Array.pv"
void Array_Scope__clear(struct Array_Scope* self);

#line 165 "src/std/Array.pv"
void Array_Scope__release(struct Array_Scope* self);

#line 172 "src/std/Array.pv"
struct Array_Scope Array_Scope__clone(struct Array_Scope* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_Scope Array_Scope__iter(struct Array_Scope* self);

#line 188 "src/std/Array.pv"
struct slice_Scope Array_Scope__as_slice(struct Array_Scope* self);

#endif
