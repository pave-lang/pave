#ifndef PAVE_ARRAY_FUNCTION_TEMP
#define PAVE_ARRAY_FUNCTION_TEMP

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct FunctionTemp;

#line 69 "src/std/Array.pv"
struct Array_FunctionTemp {
    struct trait_Allocator allocator;
    struct FunctionTemp* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <compiler/FunctionTemp.h>
#include <std/Iter_ref_FunctionTemp.h>
#include <slice_FunctionTemp.h>
struct FunctionTemp;

#line 77 "src/std/Array.pv"
struct Array_FunctionTemp Array_FunctionTemp__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_FunctionTemp Array_FunctionTemp__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_FunctionTemp Array_FunctionTemp__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_FunctionTemp__reserve(struct Array_FunctionTemp* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct FunctionTemp* Array_FunctionTemp__get(struct Array_FunctionTemp* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_FunctionTemp__append(struct Array_FunctionTemp* self, struct FunctionTemp value);

#line 125 "src/std/Array.pv"
uintptr_t Array_FunctionTemp__prepend(struct Array_FunctionTemp* self, struct FunctionTemp value);

#line 143 "src/std/Array.pv"
bool Array_FunctionTemp__remove_back(struct Array_FunctionTemp* self);

#line 154 "src/std/Array.pv"
struct FunctionTemp* Array_FunctionTemp__back(struct Array_FunctionTemp* self);

#line 160 "src/std/Array.pv"
void Array_FunctionTemp__clear(struct Array_FunctionTemp* self);

#line 165 "src/std/Array.pv"
void Array_FunctionTemp__release(struct Array_FunctionTemp* self);

#line 172 "src/std/Array.pv"
struct Array_FunctionTemp Array_FunctionTemp__clone(struct Array_FunctionTemp* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_FunctionTemp Array_FunctionTemp__iter(struct Array_FunctionTemp* self);

#line 188 "src/std/Array.pv"
struct slice_FunctionTemp Array_FunctionTemp__as_slice(struct Array_FunctionTemp* self);

#line 195 "src/std/Array.pv"
struct FunctionTemp* Array_FunctionTemp__Index__index(void* __self);


#endif
