#ifndef PAVE_ARRAY_STATEMENT
#define PAVE_ARRAY_STATEMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>
struct Statement;

#line 69 "src/std/Array.pv"
struct Array_Statement {
    struct trait_Allocator allocator;
    struct Statement* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_Statement.h>
#include <analyzer/statement/Statement.h>
#include <std/Iter_ref_Statement.h>
struct Array_Statement;
struct Statement;

#line 77 "src/std/Array.pv"
struct Array_Statement Array_Statement__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Statement Array_Statement__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Statement Array_Statement__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Statement__reserve(struct Array_Statement* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Statement* Array_Statement__get(struct Array_Statement* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Statement__append(struct Array_Statement* self, struct Statement value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Statement__prepend(struct Array_Statement* self, struct Statement value);

#line 143 "src/std/Array.pv"
bool Array_Statement__remove_back(struct Array_Statement* self);

#line 154 "src/std/Array.pv"
struct Statement* Array_Statement__back(struct Array_Statement* self);

#line 160 "src/std/Array.pv"
void Array_Statement__clear(struct Array_Statement* self);

#line 165 "src/std/Array.pv"
void Array_Statement__release(struct Array_Statement* self);

#line 172 "src/std/Array.pv"
struct Array_Statement Array_Statement__clone(struct Array_Statement* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_Statement Array_Statement__iter(struct Array_Statement* self);

#line 188 "src/std/Array.pv"
struct slice_Statement Array_Statement__as_slice(struct Array_Statement* self);

#endif
