#ifndef PAVE_ARRAY_PREPROCESSOR_ELSE_IF
#define PAVE_ARRAY_PREPROCESSOR_ELSE_IF

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct PreprocessorElseIf;

#line 69 "src/std/Array.pv"
struct Array_PreprocessorElseIf {
    struct trait_Allocator allocator;
    struct PreprocessorElseIf* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <analyzer/statement/PreprocessorElseIf.h>
#include <std/Iter_ref_PreprocessorElseIf.h>
#include <slice_PreprocessorElseIf.h>
struct PreprocessorElseIf;

#line 77 "src/std/Array.pv"
struct Array_PreprocessorElseIf Array_PreprocessorElseIf__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_PreprocessorElseIf Array_PreprocessorElseIf__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_PreprocessorElseIf Array_PreprocessorElseIf__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_PreprocessorElseIf__reserve(struct Array_PreprocessorElseIf* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct PreprocessorElseIf* Array_PreprocessorElseIf__get(struct Array_PreprocessorElseIf* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_PreprocessorElseIf__append(struct Array_PreprocessorElseIf* self, struct PreprocessorElseIf value);

#line 125 "src/std/Array.pv"
uintptr_t Array_PreprocessorElseIf__prepend(struct Array_PreprocessorElseIf* self, struct PreprocessorElseIf value);

#line 143 "src/std/Array.pv"
bool Array_PreprocessorElseIf__remove_back(struct Array_PreprocessorElseIf* self);

#line 154 "src/std/Array.pv"
struct PreprocessorElseIf* Array_PreprocessorElseIf__back(struct Array_PreprocessorElseIf* self);

#line 160 "src/std/Array.pv"
void Array_PreprocessorElseIf__clear(struct Array_PreprocessorElseIf* self);

#line 165 "src/std/Array.pv"
void Array_PreprocessorElseIf__release(struct Array_PreprocessorElseIf* self);

#line 172 "src/std/Array.pv"
struct Array_PreprocessorElseIf Array_PreprocessorElseIf__clone(struct Array_PreprocessorElseIf* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_PreprocessorElseIf Array_PreprocessorElseIf__iter(struct Array_PreprocessorElseIf* self);

#line 188 "src/std/Array.pv"
struct slice_PreprocessorElseIf Array_PreprocessorElseIf__as_slice(struct Array_PreprocessorElseIf* self);

#line 195 "src/std/Array.pv"
struct PreprocessorElseIf* Array_PreprocessorElseIf__Index__index(void* __self);


#endif
