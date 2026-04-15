#ifndef PAVE_ARRAY_FUNCTION_SCOPE
#define PAVE_ARRAY_FUNCTION_SCOPE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct FunctionScope;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_FunctionScope {
    struct trait_Allocator allocator;
    struct FunctionScope* data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_FunctionScope;
struct FunctionScope;
struct FunctionScope;
#include <std/trait_Allocator.h>
#include <std/Array_FunctionScope.h>
#include <compiler/FunctionScope.h>
#include <std/Iter_ref_FunctionScope.h>

#line 77 "src/std/Array.pv"
struct Array_FunctionScope Array_FunctionScope__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_FunctionScope Array_FunctionScope__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_FunctionScope Array_FunctionScope__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_FunctionScope__reserve(struct Array_FunctionScope* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct FunctionScope* Array_FunctionScope__get(struct Array_FunctionScope* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_FunctionScope__append(struct Array_FunctionScope* self, struct FunctionScope value);

#line 125 "src/std/Array.pv"
uintptr_t Array_FunctionScope__prepend(struct Array_FunctionScope* self, struct FunctionScope value);

#line 143 "src/std/Array.pv"
bool Array_FunctionScope__remove_back(struct Array_FunctionScope* self);

#line 154 "src/std/Array.pv"
struct FunctionScope* Array_FunctionScope__back(struct Array_FunctionScope* self);

#line 160 "src/std/Array.pv"
void Array_FunctionScope__clear(struct Array_FunctionScope* self);

#line 165 "src/std/Array.pv"
void Array_FunctionScope__release(struct Array_FunctionScope* self);

#line 172 "src/std/Array.pv"
struct Array_FunctionScope Array_FunctionScope__clone(struct Array_FunctionScope* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_FunctionScope Array_FunctionScope__iter(struct Array_FunctionScope* self);

#line 188 "src/std/Array.pv"
struct slice_FunctionScope Array_FunctionScope__as_slice(struct Array_FunctionScope* self);

#endif
