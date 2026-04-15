#ifndef PAVE_ARRAY_INLAY_HINT
#define PAVE_ARRAY_INLAY_HINT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct InlayHint;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_InlayHint {
    struct trait_Allocator allocator;
    struct InlayHint* data;
    uintptr_t length;
    uintptr_t capacity;
};
struct Array_InlayHint;
struct InlayHint;
struct InlayHint;
#include <std/trait_Allocator.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>
#include <std/Iter_ref_InlayHint.h>


#line 77 "src/std/Array.pv"
struct Array_InlayHint Array_InlayHint__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_InlayHint Array_InlayHint__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_InlayHint Array_InlayHint__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_InlayHint__reserve(struct Array_InlayHint* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct InlayHint* Array_InlayHint__get(struct Array_InlayHint* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_InlayHint__append(struct Array_InlayHint* self, struct InlayHint value);

#line 125 "src/std/Array.pv"
uintptr_t Array_InlayHint__prepend(struct Array_InlayHint* self, struct InlayHint value);

#line 143 "src/std/Array.pv"
bool Array_InlayHint__remove_back(struct Array_InlayHint* self);

#line 154 "src/std/Array.pv"
struct InlayHint* Array_InlayHint__back(struct Array_InlayHint* self);

#line 160 "src/std/Array.pv"
void Array_InlayHint__clear(struct Array_InlayHint* self);

#line 165 "src/std/Array.pv"
void Array_InlayHint__release(struct Array_InlayHint* self);

#line 172 "src/std/Array.pv"
struct Array_InlayHint Array_InlayHint__clone(struct Array_InlayHint* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_InlayHint Array_InlayHint__iter(struct Array_InlayHint* self);

#line 188 "src/std/Array.pv"
struct slice_InlayHint Array_InlayHint__as_slice(struct Array_InlayHint* self);

#endif
