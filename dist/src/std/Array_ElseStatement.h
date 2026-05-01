#ifndef PAVE_ARRAY_ELSE_STATEMENT
#define PAVE_ARRAY_ELSE_STATEMENT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct ElseStatement;

#line 69 "src/std/Array.pv"
struct Array_ElseStatement {
    struct trait_Allocator allocator;
    struct ElseStatement* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
#include <slice_ElseStatement.h>
struct Array_ElseStatement;
struct ElseStatement;

#line 77 "src/std/Array.pv"
struct Array_ElseStatement Array_ElseStatement__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ElseStatement Array_ElseStatement__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ElseStatement Array_ElseStatement__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ElseStatement__reserve(struct Array_ElseStatement* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct ElseStatement* Array_ElseStatement__get(struct Array_ElseStatement* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ElseStatement__append(struct Array_ElseStatement* self, struct ElseStatement value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ElseStatement__prepend(struct Array_ElseStatement* self, struct ElseStatement value);

#line 143 "src/std/Array.pv"
bool Array_ElseStatement__remove_back(struct Array_ElseStatement* self);

#line 154 "src/std/Array.pv"
struct ElseStatement* Array_ElseStatement__back(struct Array_ElseStatement* self);

#line 160 "src/std/Array.pv"
void Array_ElseStatement__clear(struct Array_ElseStatement* self);

#line 165 "src/std/Array.pv"
void Array_ElseStatement__release(struct Array_ElseStatement* self);

#line 172 "src/std/Array.pv"
struct Array_ElseStatement Array_ElseStatement__clone(struct Array_ElseStatement* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ElseStatement Array_ElseStatement__iter(struct Array_ElseStatement* self);

#line 188 "src/std/Array.pv"
struct slice_ElseStatement Array_ElseStatement__as_slice(struct Array_ElseStatement* self);

#endif
