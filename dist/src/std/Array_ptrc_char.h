#ifndef PAVE_ARRAY_PTRC_CHAR
#define PAVE_ARRAY_PTRC_CHAR

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct ArrayIter_ref_ptrc_char;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_ptrc_char {
    struct Allocator allocator;
    char const** data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_ptrc_char Array_ptrc_char__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ptrc_char Array_ptrc_char__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ptrc_char Array_ptrc_char__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ptrc_char__reserve(struct Array_ptrc_char* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
char const** Array_ptrc_char__get(struct Array_ptrc_char* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ptrc_char__append(struct Array_ptrc_char* self, char const* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ptrc_char__prepend(struct Array_ptrc_char* self, char const* value);

#line 143 "src/std/Array.pv"
bool Array_ptrc_char__remove_back(struct Array_ptrc_char* self);

#line 154 "src/std/Array.pv"
char const** Array_ptrc_char__back(struct Array_ptrc_char* self);

#line 160 "src/std/Array.pv"
void Array_ptrc_char__clear(struct Array_ptrc_char* self);

#line 165 "src/std/Array.pv"
void Array_ptrc_char__release(struct Array_ptrc_char* self);

#line 172 "src/std/Array.pv"
struct Array_ptrc_char Array_ptrc_char__clone(struct Array_ptrc_char* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_ptrc_char Array_ptrc_char__iter(struct Array_ptrc_char* self);

#line 189 "src/std/Array.pv"
struct slice_ptrc_char Array_ptrc_char__as_slice(struct Array_ptrc_char* self);

#endif
