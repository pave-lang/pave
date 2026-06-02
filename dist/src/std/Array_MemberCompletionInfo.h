#ifndef PAVE_ARRAY_MEMBER_COMPLETION_INFO
#define PAVE_ARRAY_MEMBER_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct MemberCompletionInfo;

#line 69 "src/std/Array.pv"
struct Array_MemberCompletionInfo {
    struct trait_Allocator allocator;
    struct MemberCompletionInfo* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_MemberCompletionInfo.h>
#include <analyzer/MemberCompletionInfo.h>
#include <std/Iter_ref_MemberCompletionInfo.h>
#include <slice_MemberCompletionInfo.h>
struct Array_MemberCompletionInfo;
struct MemberCompletionInfo;

#line 77 "src/std/Array.pv"
struct Array_MemberCompletionInfo Array_MemberCompletionInfo__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_MemberCompletionInfo Array_MemberCompletionInfo__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_MemberCompletionInfo Array_MemberCompletionInfo__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_MemberCompletionInfo__reserve(struct Array_MemberCompletionInfo* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct MemberCompletionInfo* Array_MemberCompletionInfo__get(struct Array_MemberCompletionInfo* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_MemberCompletionInfo__append(struct Array_MemberCompletionInfo* self, struct MemberCompletionInfo value);

#line 125 "src/std/Array.pv"
uintptr_t Array_MemberCompletionInfo__prepend(struct Array_MemberCompletionInfo* self, struct MemberCompletionInfo value);

#line 143 "src/std/Array.pv"
bool Array_MemberCompletionInfo__remove_back(struct Array_MemberCompletionInfo* self);

#line 154 "src/std/Array.pv"
struct MemberCompletionInfo* Array_MemberCompletionInfo__back(struct Array_MemberCompletionInfo* self);

#line 160 "src/std/Array.pv"
void Array_MemberCompletionInfo__clear(struct Array_MemberCompletionInfo* self);

#line 165 "src/std/Array.pv"
void Array_MemberCompletionInfo__release(struct Array_MemberCompletionInfo* self);

#line 172 "src/std/Array.pv"
struct Array_MemberCompletionInfo Array_MemberCompletionInfo__clone(struct Array_MemberCompletionInfo* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_MemberCompletionInfo Array_MemberCompletionInfo__iter(struct Array_MemberCompletionInfo* self);

#line 188 "src/std/Array.pv"
struct slice_MemberCompletionInfo Array_MemberCompletionInfo__as_slice(struct Array_MemberCompletionInfo* self);

#line 195 "src/std/Array.pv"
struct MemberCompletionInfo* Array_MemberCompletionInfo__Index__index(void* __self);


#endif
