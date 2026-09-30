#ifndef PAVE_ARRAY_U32
#define PAVE_ARRAY_U32

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_u32 {
    struct trait_Allocator allocator;
    uint32_t* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Iter_ref_u32.h>
#include <slice_u32.h>

#line 77 "src/std/Array.pv"
struct Array_u32 Array_u32__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_u32 Array_u32__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_u32 Array_u32__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_u32__reserve(struct Array_u32* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
uint32_t* Array_u32__get(struct Array_u32* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_u32__append(struct Array_u32* self, uint32_t value);

#line 125 "src/std/Array.pv"
uintptr_t Array_u32__prepend(struct Array_u32* self, uint32_t value);

#line 143 "src/std/Array.pv"
bool Array_u32__remove_back(struct Array_u32* self);

#line 154 "src/std/Array.pv"
uint32_t* Array_u32__back(struct Array_u32* self);

#line 160 "src/std/Array.pv"
void Array_u32__clear(struct Array_u32* self);

#line 165 "src/std/Array.pv"
void Array_u32__release(struct Array_u32* self);

#line 172 "src/std/Array.pv"
struct Array_u32 Array_u32__clone(struct Array_u32* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_u32 Array_u32__iter(struct Array_u32* self);

#line 188 "src/std/Array.pv"
struct slice_u32 Array_u32__as_slice(struct Array_u32* self);

#line 195 "src/std/Array.pv"
uint32_t* Array_u32__Index__index(void* __self);


#endif
