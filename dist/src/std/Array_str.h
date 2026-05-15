#ifndef PAVE_ARRAY_STR
#define PAVE_ARRAY_STR

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct str;

#line 69 "src/std/Array.pv"
struct Array_str {
    struct trait_Allocator allocator;
    struct str* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_str.h>
#include <std/str.h>
#include <std/Iter_ref_str.h>
#include <slice_str.h>
struct Array_str;
struct str;

#line 77 "src/std/Array.pv"
struct Array_str Array_str__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_str Array_str__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_str Array_str__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_str__reserve(struct Array_str* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct str* Array_str__get(struct Array_str* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_str__append(struct Array_str* self, struct str value);

#line 125 "src/std/Array.pv"
uintptr_t Array_str__prepend(struct Array_str* self, struct str value);

#line 143 "src/std/Array.pv"
bool Array_str__remove_back(struct Array_str* self);

#line 154 "src/std/Array.pv"
struct str* Array_str__back(struct Array_str* self);

#line 160 "src/std/Array.pv"
void Array_str__clear(struct Array_str* self);

#line 165 "src/std/Array.pv"
void Array_str__release(struct Array_str* self);

#line 172 "src/std/Array.pv"
struct Array_str Array_str__clone(struct Array_str* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_str Array_str__iter(struct Array_str* self);

#line 188 "src/std/Array.pv"
struct slice_str Array_str__as_slice(struct Array_str* self);

#endif
