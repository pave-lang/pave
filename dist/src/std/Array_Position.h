#ifndef PAVE_ARRAY_POSITION
#define PAVE_ARRAY_POSITION

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct Position;

#line 69 "src/std/Array.pv"
struct Array_Position {
    struct trait_Allocator allocator;
    struct Position* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_Position.h>
#include <analyzer/Position.h>
#include <std/Iter_ref_Position.h>
#include <slice_Position.h>
struct Array_Position;
struct Position;

#line 77 "src/std/Array.pv"
struct Array_Position Array_Position__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Position Array_Position__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Position Array_Position__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Position__reserve(struct Array_Position* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Position* Array_Position__get(struct Array_Position* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Position__append(struct Array_Position* self, struct Position value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Position__prepend(struct Array_Position* self, struct Position value);

#line 143 "src/std/Array.pv"
bool Array_Position__remove_back(struct Array_Position* self);

#line 154 "src/std/Array.pv"
struct Position* Array_Position__back(struct Array_Position* self);

#line 160 "src/std/Array.pv"
void Array_Position__clear(struct Array_Position* self);

#line 165 "src/std/Array.pv"
void Array_Position__release(struct Array_Position* self);

#line 172 "src/std/Array.pv"
struct Array_Position Array_Position__clone(struct Array_Position* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_Position Array_Position__iter(struct Array_Position* self);

#line 188 "src/std/Array.pv"
struct slice_Position Array_Position__as_slice(struct Array_Position* self);

#line 195 "src/std/Array.pv"
struct Position* Array_Position__Index__index(void* __self);


#endif
