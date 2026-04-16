#ifndef PAVE_ARRAY_PARAMETER
#define PAVE_ARRAY_PARAMETER

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct Parameter;

#line 69 "src/std/Array.pv"
struct Array_Parameter {
    struct trait_Allocator allocator;
    struct Parameter* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/Iter_ref_Parameter.h>
struct Array_Parameter;
struct Parameter;

#line 77 "src/std/Array.pv"
struct Array_Parameter Array_Parameter__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_Parameter Array_Parameter__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_Parameter Array_Parameter__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_Parameter__reserve(struct Array_Parameter* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Parameter* Array_Parameter__get(struct Array_Parameter* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_Parameter__append(struct Array_Parameter* self, struct Parameter value);

#line 125 "src/std/Array.pv"
uintptr_t Array_Parameter__prepend(struct Array_Parameter* self, struct Parameter value);

#line 143 "src/std/Array.pv"
bool Array_Parameter__remove_back(struct Array_Parameter* self);

#line 154 "src/std/Array.pv"
struct Parameter* Array_Parameter__back(struct Array_Parameter* self);

#line 160 "src/std/Array.pv"
void Array_Parameter__clear(struct Array_Parameter* self);

#line 165 "src/std/Array.pv"
void Array_Parameter__release(struct Array_Parameter* self);

#line 172 "src/std/Array.pv"
struct Array_Parameter Array_Parameter__clone(struct Array_Parameter* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_Parameter Array_Parameter__iter(struct Array_Parameter* self);

#line 188 "src/std/Array.pv"
struct slice_Parameter Array_Parameter__as_slice(struct Array_Parameter* self);

#endif
