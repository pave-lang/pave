#ifndef PAVE_ARRAY_COMPLETION_INFO
#define PAVE_ARRAY_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct CompletionInfo;

#line 69 "src/std/Array.pv"
struct Array_CompletionInfo {
    struct trait_Allocator allocator;
    struct CompletionInfo* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <analyzer/CompletionInfo.h>
#include <std/Iter_ref_CompletionInfo.h>
#include <slice_CompletionInfo.h>
struct CompletionInfo;

#line 77 "src/std/Array.pv"
struct Array_CompletionInfo Array_CompletionInfo__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_CompletionInfo Array_CompletionInfo__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_CompletionInfo Array_CompletionInfo__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_CompletionInfo__reserve(struct Array_CompletionInfo* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct CompletionInfo* Array_CompletionInfo__get(struct Array_CompletionInfo* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_CompletionInfo__append(struct Array_CompletionInfo* self, struct CompletionInfo value);

#line 125 "src/std/Array.pv"
uintptr_t Array_CompletionInfo__prepend(struct Array_CompletionInfo* self, struct CompletionInfo value);

#line 143 "src/std/Array.pv"
bool Array_CompletionInfo__remove_back(struct Array_CompletionInfo* self);

#line 154 "src/std/Array.pv"
struct CompletionInfo* Array_CompletionInfo__back(struct Array_CompletionInfo* self);

#line 160 "src/std/Array.pv"
void Array_CompletionInfo__clear(struct Array_CompletionInfo* self);

#line 165 "src/std/Array.pv"
void Array_CompletionInfo__release(struct Array_CompletionInfo* self);

#line 172 "src/std/Array.pv"
struct Array_CompletionInfo Array_CompletionInfo__clone(struct Array_CompletionInfo* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_CompletionInfo Array_CompletionInfo__iter(struct Array_CompletionInfo* self);

#line 188 "src/std/Array.pv"
struct slice_CompletionInfo Array_CompletionInfo__as_slice(struct Array_CompletionInfo* self);

#line 195 "src/std/Array.pv"
struct CompletionInfo* Array_CompletionInfo__Index__index(void* __self);


#endif
