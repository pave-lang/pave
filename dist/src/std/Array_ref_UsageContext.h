#ifndef PAVE_ARRAY_REF_USAGE_CONTEXT
#define PAVE_ARRAY_REF_USAGE_CONTEXT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_ref_UsageContext {
    struct trait_Allocator allocator;
    struct UsageContext** data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Iter_ref_ref_UsageContext.h>
#include <slice_ref_UsageContext.h>
struct UsageContext;

#line 77 "src/std/Array.pv"
struct Array_ref_UsageContext Array_ref_UsageContext__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_UsageContext Array_ref_UsageContext__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_UsageContext Array_ref_UsageContext__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_UsageContext__reserve(struct Array_ref_UsageContext* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct UsageContext** Array_ref_UsageContext__get(struct Array_ref_UsageContext* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_UsageContext__append(struct Array_ref_UsageContext* self, struct UsageContext* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_UsageContext__prepend(struct Array_ref_UsageContext* self, struct UsageContext* value);

#line 143 "src/std/Array.pv"
bool Array_ref_UsageContext__remove_back(struct Array_ref_UsageContext* self);

#line 154 "src/std/Array.pv"
struct UsageContext** Array_ref_UsageContext__back(struct Array_ref_UsageContext* self);

#line 160 "src/std/Array.pv"
void Array_ref_UsageContext__clear(struct Array_ref_UsageContext* self);

#line 165 "src/std/Array.pv"
void Array_ref_UsageContext__release(struct Array_ref_UsageContext* self);

#line 172 "src/std/Array.pv"
struct Array_ref_UsageContext Array_ref_UsageContext__clone(struct Array_ref_UsageContext* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ref_UsageContext Array_ref_UsageContext__iter(struct Array_ref_UsageContext* self);

#line 188 "src/std/Array.pv"
struct slice_ref_UsageContext Array_ref_UsageContext__as_slice(struct Array_ref_UsageContext* self);

#line 195 "src/std/Array.pv"
struct UsageContext** Array_ref_UsageContext__Index__index(void* __self);


#endif
