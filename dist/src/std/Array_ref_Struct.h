#ifndef PAVE_ARRAY_REF_STRUCT
#define PAVE_ARRAY_REF_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_Struct {
    struct trait_Allocator allocator;
    struct Struct** data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Iter_ref_ref_Struct.h>
#include <slice_ref_Struct.h>
struct Struct;

#line 77 "src/std/Array.pv"
struct Array_ref_Struct Array_ref_Struct__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_Struct Array_ref_Struct__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_Struct Array_ref_Struct__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_Struct__reserve(struct Array_ref_Struct* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct Struct** Array_ref_Struct__get(struct Array_ref_Struct* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_Struct__append(struct Array_ref_Struct* self, struct Struct* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_Struct__prepend(struct Array_ref_Struct* self, struct Struct* value);

#line 143 "src/std/Array.pv"
bool Array_ref_Struct__remove_back(struct Array_ref_Struct* self);

#line 154 "src/std/Array.pv"
struct Struct** Array_ref_Struct__back(struct Array_ref_Struct* self);

#line 160 "src/std/Array.pv"
void Array_ref_Struct__clear(struct Array_ref_Struct* self);

#line 165 "src/std/Array.pv"
void Array_ref_Struct__release(struct Array_ref_Struct* self);

#line 172 "src/std/Array.pv"
struct Array_ref_Struct Array_ref_Struct__clone(struct Array_ref_Struct* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_Struct Array_ref_Struct__iter(struct Array_ref_Struct* self);

#line 188 "src/std/Array.pv"
struct slice_ref_Struct Array_ref_Struct__as_slice(struct Array_ref_Struct* self);

#line 195 "src/std/Array.pv"
struct Struct** Array_ref_Struct__Index__index(void* __self);


#endif
