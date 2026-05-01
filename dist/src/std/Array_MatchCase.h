#ifndef PAVE_ARRAY_MATCH_CASE
#define PAVE_ARRAY_MATCH_CASE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct MatchCase;

#line 69 "src/std/Array.pv"
struct Array_MatchCase {
    struct trait_Allocator allocator;
    struct MatchCase* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
#include <slice_MatchCase.h>
struct Array_MatchCase;
struct MatchCase;

#line 77 "src/std/Array.pv"
struct Array_MatchCase Array_MatchCase__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_MatchCase Array_MatchCase__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_MatchCase Array_MatchCase__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_MatchCase__reserve(struct Array_MatchCase* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct MatchCase* Array_MatchCase__get(struct Array_MatchCase* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_MatchCase__append(struct Array_MatchCase* self, struct MatchCase value);

#line 125 "src/std/Array.pv"
uintptr_t Array_MatchCase__prepend(struct Array_MatchCase* self, struct MatchCase value);

#line 143 "src/std/Array.pv"
bool Array_MatchCase__remove_back(struct Array_MatchCase* self);

#line 154 "src/std/Array.pv"
struct MatchCase* Array_MatchCase__back(struct Array_MatchCase* self);

#line 160 "src/std/Array.pv"
void Array_MatchCase__clear(struct Array_MatchCase* self);

#line 165 "src/std/Array.pv"
void Array_MatchCase__release(struct Array_MatchCase* self);

#line 172 "src/std/Array.pv"
struct Array_MatchCase Array_MatchCase__clone(struct Array_MatchCase* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_MatchCase Array_MatchCase__iter(struct Array_MatchCase* self);

#line 188 "src/std/Array.pv"
struct slice_MatchCase Array_MatchCase__as_slice(struct Array_MatchCase* self);

#endif
