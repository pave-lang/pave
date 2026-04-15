#ifndef PAVE_ARRAY_USAGE_CONTEXT
#define PAVE_ARRAY_USAGE_CONTEXT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct UsageContext;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_UsageContext {
    struct trait_Allocator allocator;
    struct UsageContext* data;
    uintptr_t length;
    uintptr_t capacity;
};
struct Array_UsageContext;
struct UsageContext;
struct UsageContext;
#include <std/trait_Allocator.h>
#include <std/Array_UsageContext.h>
#include <compiler/UsageContext.h>
#include <std/Iter_ref_UsageContext.h>


#line 77 "src/std/Array.pv"
struct Array_UsageContext Array_UsageContext__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_UsageContext Array_UsageContext__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_UsageContext Array_UsageContext__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_UsageContext__reserve(struct Array_UsageContext* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct UsageContext* Array_UsageContext__get(struct Array_UsageContext* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_UsageContext__append(struct Array_UsageContext* self, struct UsageContext value);

#line 125 "src/std/Array.pv"
uintptr_t Array_UsageContext__prepend(struct Array_UsageContext* self, struct UsageContext value);

#line 143 "src/std/Array.pv"
bool Array_UsageContext__remove_back(struct Array_UsageContext* self);

#line 154 "src/std/Array.pv"
struct UsageContext* Array_UsageContext__back(struct Array_UsageContext* self);

#line 160 "src/std/Array.pv"
void Array_UsageContext__clear(struct Array_UsageContext* self);

#line 165 "src/std/Array.pv"
void Array_UsageContext__release(struct Array_UsageContext* self);

#line 172 "src/std/Array.pv"
struct Array_UsageContext Array_UsageContext__clone(struct Array_UsageContext* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_UsageContext Array_UsageContext__iter(struct Array_UsageContext* self);

#line 188 "src/std/Array.pv"
struct slice_UsageContext Array_UsageContext__as_slice(struct Array_UsageContext* self);

#endif
