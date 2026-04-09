#ifndef PAVE_ARRAY_INVOKE_ARGUMENT
#define PAVE_ARRAY_INVOKE_ARGUMENT

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct InvokeArgument;
struct ArrayIter_ref_InvokeArgument;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_InvokeArgument {
    struct Allocator allocator;
    struct InvokeArgument* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_InvokeArgument__reserve(struct Array_InvokeArgument* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct InvokeArgument* Array_InvokeArgument__get(struct Array_InvokeArgument* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_InvokeArgument__append(struct Array_InvokeArgument* self, struct InvokeArgument value);

#line 125 "src/std/Array.pv"
uintptr_t Array_InvokeArgument__prepend(struct Array_InvokeArgument* self, struct InvokeArgument value);

#line 143 "src/std/Array.pv"
bool Array_InvokeArgument__remove_back(struct Array_InvokeArgument* self);

#line 154 "src/std/Array.pv"
struct InvokeArgument* Array_InvokeArgument__back(struct Array_InvokeArgument* self);

#line 160 "src/std/Array.pv"
void Array_InvokeArgument__clear(struct Array_InvokeArgument* self);

#line 165 "src/std/Array.pv"
void Array_InvokeArgument__release(struct Array_InvokeArgument* self);

#line 172 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__clone(struct Array_InvokeArgument* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_InvokeArgument Array_InvokeArgument__iter(struct Array_InvokeArgument* self);

#line 188 "src/std/Array.pv"
struct slice_InvokeArgument Array_InvokeArgument__as_slice(struct Array_InvokeArgument* self);

#endif
