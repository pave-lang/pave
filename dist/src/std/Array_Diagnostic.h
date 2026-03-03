#ifndef PAVE_ARRAY_DIAGNOSTIC
#define PAVE_ARRAY_DIAGNOSTIC

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct Diagnostic;
struct ArrayIter_ref_Diagnostic;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_Diagnostic {
    struct Allocator allocator;
    struct Diagnostic* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_Diagnostic Array_Diagnostic__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Diagnostic Array_Diagnostic__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Diagnostic Array_Diagnostic__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Diagnostic__reserve(struct Array_Diagnostic* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Diagnostic* Array_Diagnostic__get(struct Array_Diagnostic* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Diagnostic__append(struct Array_Diagnostic* self, struct Diagnostic value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Diagnostic__prepend(struct Array_Diagnostic* self, struct Diagnostic value);

#line 143 "src/std/Array.pv"
bool Array_Diagnostic__remove_back(struct Array_Diagnostic* self);

#line 154 "src/std/Array.pv"
struct Diagnostic* Array_Diagnostic__back(struct Array_Diagnostic* self);

#line 160 "src/std/Array.pv"
void Array_Diagnostic__clear(struct Array_Diagnostic* self);

#line 165 "src/std/Array.pv"
void Array_Diagnostic__release(struct Array_Diagnostic* self);

#line 172 "src/std/Array.pv"
struct Array_Diagnostic Array_Diagnostic__clone(struct Array_Diagnostic* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_Diagnostic Array_Diagnostic__iter(struct Array_Diagnostic* self);

#line 189 "src/std/Array.pv"
struct slice_Diagnostic Array_Diagnostic__as_slice(struct Array_Diagnostic* self);

#endif
