#ifndef PAVE_ARRAY_CHAR
#define PAVE_ARRAY_CHAR

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_char {
    struct trait_Allocator allocator;
    char* data;
    uintptr_t length;
    uintptr_t capacity;
};
struct Array_char;
#include <std/trait_Allocator.h>
#include <std/Array_char.h>
#include <std/Iter_ref_char.h>


#line 77 "src/std/Array.pv"
struct Array_char Array_char__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_char Array_char__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_char Array_char__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_char__reserve(struct Array_char* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
char* Array_char__get(struct Array_char* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_char__append(struct Array_char* self, char value);

#line 125 "src/std/Array.pv"
uintptr_t Array_char__prepend(struct Array_char* self, char value);

#line 143 "src/std/Array.pv"
bool Array_char__remove_back(struct Array_char* self);

#line 154 "src/std/Array.pv"
char* Array_char__back(struct Array_char* self);

#line 160 "src/std/Array.pv"
void Array_char__clear(struct Array_char* self);

#line 165 "src/std/Array.pv"
void Array_char__release(struct Array_char* self);

#line 172 "src/std/Array.pv"
struct Array_char Array_char__clone(struct Array_char* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_char Array_char__iter(struct Array_char* self);

#line 188 "src/std/Array.pv"
struct slice_char Array_char__as_slice(struct Array_char* self);

#endif
