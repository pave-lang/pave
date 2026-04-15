#ifndef PAVE_ARRAY_REF_TOKEN
#define PAVE_ARRAY_REF_TOKEN

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Token;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Token {
    struct trait_Allocator allocator;
    struct Token** data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_ref_Token;
struct Token;
struct Token;
struct Token;
#include <std/trait_Allocator.h>
#include <std/Array_ref_Token.h>
#include <std/Iter_ref_ref_Token.h>

#line 77 "src/std/Array.pv"
struct Array_ref_Token Array_ref_Token__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Token Array_ref_Token__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Token Array_ref_Token__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Token__reserve(struct Array_ref_Token* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Token** Array_ref_Token__get(struct Array_ref_Token* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Token__append(struct Array_ref_Token* self, struct Token* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Token__prepend(struct Array_ref_Token* self, struct Token* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Token__remove_back(struct Array_ref_Token* self);

#line 154 "src/std/Array.pv"
struct Token** Array_ref_Token__back(struct Array_ref_Token* self);

#line 160 "src/std/Array.pv"
void Array_ref_Token__clear(struct Array_ref_Token* self);

#line 165 "src/std/Array.pv"
void Array_ref_Token__release(struct Array_ref_Token* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Token Array_ref_Token__clone(struct Array_ref_Token* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Token Array_ref_Token__iter(struct Array_ref_Token* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Token Array_ref_Token__as_slice(struct Array_ref_Token* self);

#endif
