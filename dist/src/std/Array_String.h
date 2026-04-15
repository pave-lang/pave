#ifndef PAVE_ARRAY_STRING
#define PAVE_ARRAY_STRING

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct String;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_String {
    struct trait_Allocator allocator;
    struct String* data;
    uintptr_t length;
    uintptr_t capacity;
};
struct Array_String;
struct String;
struct String;
#include <std/trait_Allocator.h>
#include <std/Array_String.h>
#include <std/String.h>
#include <std/Iter_ref_String.h>


#line 77 "src/std/Array.pv"
struct Array_String Array_String__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_String Array_String__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_String Array_String__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_String__reserve(struct Array_String* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct String* Array_String__get(struct Array_String* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_String__append(struct Array_String* self, struct String value);

#line 125 "src/std/Array.pv"
uintptr_t Array_String__prepend(struct Array_String* self, struct String value);

#line 143 "src/std/Array.pv"
bool Array_String__remove_back(struct Array_String* self);

#line 154 "src/std/Array.pv"
struct String* Array_String__back(struct Array_String* self);

#line 160 "src/std/Array.pv"
void Array_String__clear(struct Array_String* self);

#line 165 "src/std/Array.pv"
void Array_String__release(struct Array_String* self);

#line 172 "src/std/Array.pv"
struct Array_String Array_String__clone(struct Array_String* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_String Array_String__iter(struct Array_String* self);

#line 188 "src/std/Array.pv"
struct slice_String Array_String__as_slice(struct Array_String* self);

#endif
