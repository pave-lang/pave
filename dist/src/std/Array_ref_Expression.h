#ifndef PAVE_ARRAY_REF_EXPRESSION
#define PAVE_ARRAY_REF_EXPRESSION

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Expression;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Expression {
    struct trait_Allocator allocator;
    struct Expression** data;
    uintptr_t length;
    uintptr_t capacity;
};
struct Array_ref_Expression;
struct Expression;
struct Expression;
struct Expression;
#include <std/trait_Allocator.h>
#include <std/Array_ref_Expression.h>
#include <std/Iter_ref_ref_Expression.h>


#line 77 "src/std/Array.pv"
struct Array_ref_Expression Array_ref_Expression__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Expression Array_ref_Expression__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Expression Array_ref_Expression__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Expression__reserve(struct Array_ref_Expression* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Expression** Array_ref_Expression__get(struct Array_ref_Expression* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Expression__append(struct Array_ref_Expression* self, struct Expression* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Expression__prepend(struct Array_ref_Expression* self, struct Expression* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Expression__remove_back(struct Array_ref_Expression* self);

#line 154 "src/std/Array.pv"
struct Expression** Array_ref_Expression__back(struct Array_ref_Expression* self);

#line 160 "src/std/Array.pv"
void Array_ref_Expression__clear(struct Array_ref_Expression* self);

#line 165 "src/std/Array.pv"
void Array_ref_Expression__release(struct Array_ref_Expression* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Expression Array_ref_Expression__clone(struct Array_ref_Expression* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Expression Array_ref_Expression__iter(struct Array_ref_Expression* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Expression Array_ref_Expression__as_slice(struct Array_ref_Expression* self);

#endif
