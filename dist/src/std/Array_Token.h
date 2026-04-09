#ifndef PAVE_ARRAY_TOKEN
#define PAVE_ARRAY_TOKEN

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct Token;
struct ArrayIter_ref_Token;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_Token {
    struct Allocator allocator;
    struct Token* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_Token Array_Token__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Token Array_Token__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Token Array_Token__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Token__reserve(struct Array_Token* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Token* Array_Token__get(struct Array_Token* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Token__append(struct Array_Token* self, struct Token value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Token__prepend(struct Array_Token* self, struct Token value);

#line 143 "src/std/Array.pv"
bool Array_Token__remove_back(struct Array_Token* self);

#line 154 "src/std/Array.pv"
struct Token* Array_Token__back(struct Array_Token* self);

#line 160 "src/std/Array.pv"
void Array_Token__clear(struct Array_Token* self);

#line 165 "src/std/Array.pv"
void Array_Token__release(struct Array_Token* self);

#line 172 "src/std/Array.pv"
struct Array_Token Array_Token__clone(struct Array_Token* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_Token Array_Token__iter(struct Array_Token* self);

#line 188 "src/std/Array.pv"
struct slice_Token Array_Token__as_slice(struct Array_Token* self);

#endif
