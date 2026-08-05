#ifndef PAVE_ARRAY_NULL_NARROWING
#define PAVE_ARRAY_NULL_NARROWING

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct NullNarrowing;

#line 69 "src/std/Array.pv"
struct Array_NullNarrowing {
    struct trait_Allocator allocator;
    struct NullNarrowing* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <analyzer/expression/NullNarrowing.h>
#include <std/Iter_ref_NullNarrowing.h>
#include <slice_NullNarrowing.h>
struct NullNarrowing;

#line 77 "src/std/Array.pv"
struct Array_NullNarrowing Array_NullNarrowing__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_NullNarrowing Array_NullNarrowing__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_NullNarrowing Array_NullNarrowing__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_NullNarrowing__reserve(struct Array_NullNarrowing* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct NullNarrowing* Array_NullNarrowing__get(struct Array_NullNarrowing* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_NullNarrowing__append(struct Array_NullNarrowing* self, struct NullNarrowing value);

#line 125 "src/std/Array.pv"
uintptr_t Array_NullNarrowing__prepend(struct Array_NullNarrowing* self, struct NullNarrowing value);

#line 143 "src/std/Array.pv"
bool Array_NullNarrowing__remove_back(struct Array_NullNarrowing* self);

#line 154 "src/std/Array.pv"
struct NullNarrowing* Array_NullNarrowing__back(struct Array_NullNarrowing* self);

#line 160 "src/std/Array.pv"
void Array_NullNarrowing__clear(struct Array_NullNarrowing* self);

#line 165 "src/std/Array.pv"
void Array_NullNarrowing__release(struct Array_NullNarrowing* self);

#line 172 "src/std/Array.pv"
struct Array_NullNarrowing Array_NullNarrowing__clone(struct Array_NullNarrowing* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_NullNarrowing Array_NullNarrowing__iter(struct Array_NullNarrowing* self);

#line 188 "src/std/Array.pv"
struct slice_NullNarrowing Array_NullNarrowing__as_slice(struct Array_NullNarrowing* self);

#line 195 "src/std/Array.pv"
struct NullNarrowing* Array_NullNarrowing__Index__index(void* __self);


#endif
