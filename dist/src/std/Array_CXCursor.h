#ifndef PAVE_ARRAY_CXCURSOR
#define PAVE_ARRAY_CXCURSOR

#include "clang-c/Index.h"
#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_CXCursor {
    struct trait_Allocator allocator;
    CXCursor* data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_CXCursor;
#include <std/trait_Allocator.h>
#include <std/Array_CXCursor.h>
#include <std/Iter_ref_CXCursor.h>

#line 77 "src/std/Array.pv"
struct Array_CXCursor Array_CXCursor__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_CXCursor Array_CXCursor__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_CXCursor Array_CXCursor__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_CXCursor__reserve(struct Array_CXCursor* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
CXCursor* Array_CXCursor__get(struct Array_CXCursor* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_CXCursor__append(struct Array_CXCursor* self, CXCursor value);

#line 125 "src/std/Array.pv"
uintptr_t Array_CXCursor__prepend(struct Array_CXCursor* self, CXCursor value);

#line 143 "src/std/Array.pv"
bool Array_CXCursor__remove_back(struct Array_CXCursor* self);

#line 154 "src/std/Array.pv"
CXCursor* Array_CXCursor__back(struct Array_CXCursor* self);

#line 160 "src/std/Array.pv"
void Array_CXCursor__clear(struct Array_CXCursor* self);

#line 165 "src/std/Array.pv"
void Array_CXCursor__release(struct Array_CXCursor* self);

#line 172 "src/std/Array.pv"
struct Array_CXCursor Array_CXCursor__clone(struct Array_CXCursor* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_CXCursor Array_CXCursor__iter(struct Array_CXCursor* self);

#line 188 "src/std/Array.pv"
struct slice_CXCursor Array_CXCursor__as_slice(struct Array_CXCursor* self);

#endif
