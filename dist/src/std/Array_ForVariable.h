#ifndef PAVE_ARRAY_FOR_VARIABLE
#define PAVE_ARRAY_FOR_VARIABLE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct ForVariable;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ForVariable {
    struct trait_Allocator allocator;
    struct ForVariable* data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_ForVariable;
struct ForVariable;
struct ForVariable;
#include <std/trait_Allocator.h>
#include <std/Array_ForVariable.h>
#include <analyzer/statement/ForVariable.h>
#include <std/Iter_ref_ForVariable.h>

#line 77 "src/std/Array.pv"
struct Array_ForVariable Array_ForVariable__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ForVariable Array_ForVariable__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ForVariable Array_ForVariable__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ForVariable__reserve(struct Array_ForVariable* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct ForVariable* Array_ForVariable__get(struct Array_ForVariable* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ForVariable__append(struct Array_ForVariable* self, struct ForVariable value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ForVariable__prepend(struct Array_ForVariable* self, struct ForVariable value);

#line 143 "src/std/Array.pv"
bool Array_ForVariable__remove_back(struct Array_ForVariable* self);

#line 154 "src/std/Array.pv"
struct ForVariable* Array_ForVariable__back(struct Array_ForVariable* self);

#line 160 "src/std/Array.pv"
void Array_ForVariable__clear(struct Array_ForVariable* self);

#line 165 "src/std/Array.pv"
void Array_ForVariable__release(struct Array_ForVariable* self);

#line 172 "src/std/Array.pv"
struct Array_ForVariable Array_ForVariable__clone(struct Array_ForVariable* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ForVariable Array_ForVariable__iter(struct Array_ForVariable* self);

#line 188 "src/std/Array.pv"
struct slice_ForVariable Array_ForVariable__as_slice(struct Array_ForVariable* self);

#endif
