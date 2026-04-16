#ifndef PAVE_ARRAY_MATCH_PATTERN
#define PAVE_ARRAY_MATCH_PATTERN

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>
struct MatchPattern;

#line 69 "src/std/Array.pv"
struct Array_MatchPattern {
    struct trait_Allocator allocator;
    struct MatchPattern* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>
#include <std/Iter_ref_MatchPattern.h>
struct Array_MatchPattern;
struct MatchPattern;

#line 77 "src/std/Array.pv"
struct Array_MatchPattern Array_MatchPattern__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_MatchPattern Array_MatchPattern__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_MatchPattern Array_MatchPattern__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_MatchPattern__reserve(struct Array_MatchPattern* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct MatchPattern* Array_MatchPattern__get(struct Array_MatchPattern* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_MatchPattern__append(struct Array_MatchPattern* self, struct MatchPattern value);

#line 125 "src/std/Array.pv"
uintptr_t Array_MatchPattern__prepend(struct Array_MatchPattern* self, struct MatchPattern value);

#line 143 "src/std/Array.pv"
bool Array_MatchPattern__remove_back(struct Array_MatchPattern* self);

#line 154 "src/std/Array.pv"
struct MatchPattern* Array_MatchPattern__back(struct Array_MatchPattern* self);

#line 160 "src/std/Array.pv"
void Array_MatchPattern__clear(struct Array_MatchPattern* self);

#line 165 "src/std/Array.pv"
void Array_MatchPattern__release(struct Array_MatchPattern* self);

#line 172 "src/std/Array.pv"
struct Array_MatchPattern Array_MatchPattern__clone(struct Array_MatchPattern* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_MatchPattern Array_MatchPattern__iter(struct Array_MatchPattern* self);

#line 188 "src/std/Array.pv"
struct slice_MatchPattern Array_MatchPattern__as_slice(struct Array_MatchPattern* self);

#endif
