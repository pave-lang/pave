#ifndef PAVE_ARRAY_TOKEN
#define PAVE_ARRAY_TOKEN

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct Token;

#line 69 "src/std/Array.pv"
struct Array_Token {
    struct trait_Allocator allocator;
    struct Token* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <std/Iter_ref_Token.h>
struct Array_Token;
struct Token;

#line 77 "src/std/Array.pv"
struct Array_Token Array_Token__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Token Array_Token__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Token Array_Token__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

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
struct Array_Token Array_Token__clone(struct Array_Token* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_Token Array_Token__iter(struct Array_Token* self);

#line 188 "src/std/Array.pv"
struct slice_Token Array_Token__as_slice(struct Array_Token* self);

#endif
