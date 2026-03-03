#ifndef PAVE_ARRAY_ENUM_VARIANT_PARAMETER
#define PAVE_ARRAY_ENUM_VARIANT_PARAMETER

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct EnumVariantParameter;
struct ArrayIter_ref_EnumVariantParameter;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_EnumVariantParameter {
    struct Allocator allocator;
    struct EnumVariantParameter* data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_EnumVariantParameter Array_EnumVariantParameter__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_EnumVariantParameter Array_EnumVariantParameter__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_EnumVariantParameter Array_EnumVariantParameter__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_EnumVariantParameter__reserve(struct Array_EnumVariantParameter* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct EnumVariantParameter* Array_EnumVariantParameter__get(struct Array_EnumVariantParameter* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_EnumVariantParameter__append(struct Array_EnumVariantParameter* self, struct EnumVariantParameter value);

#line 125 "src/std/Array.pv"
uintptr_t Array_EnumVariantParameter__prepend(struct Array_EnumVariantParameter* self, struct EnumVariantParameter value);

#line 143 "src/std/Array.pv"
bool Array_EnumVariantParameter__remove_back(struct Array_EnumVariantParameter* self);

#line 154 "src/std/Array.pv"
struct EnumVariantParameter* Array_EnumVariantParameter__back(struct Array_EnumVariantParameter* self);

#line 160 "src/std/Array.pv"
void Array_EnumVariantParameter__clear(struct Array_EnumVariantParameter* self);

#line 165 "src/std/Array.pv"
void Array_EnumVariantParameter__release(struct Array_EnumVariantParameter* self);

#line 172 "src/std/Array.pv"
struct Array_EnumVariantParameter Array_EnumVariantParameter__clone(struct Array_EnumVariantParameter* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_EnumVariantParameter Array_EnumVariantParameter__iter(struct Array_EnumVariantParameter* self);

#line 189 "src/std/Array.pv"
struct slice_EnumVariantParameter Array_EnumVariantParameter__as_slice(struct Array_EnumVariantParameter* self);

#endif
