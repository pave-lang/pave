#ifndef PAVE_ARRAY_TEST_INFO
#define PAVE_ARRAY_TEST_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct TestInfo;

#line 69 "src/std/Array.pv"
struct Array_TestInfo {
    struct trait_Allocator allocator;
    struct TestInfo* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_TestInfo.h>
#include <analyzer/TestInfo.h>
#include <std/Iter_ref_TestInfo.h>
#include <slice_TestInfo.h>
struct Array_TestInfo;
struct TestInfo;

#line 77 "src/std/Array.pv"
struct Array_TestInfo Array_TestInfo__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_TestInfo Array_TestInfo__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_TestInfo Array_TestInfo__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_TestInfo__reserve(struct Array_TestInfo* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct TestInfo* Array_TestInfo__get(struct Array_TestInfo* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_TestInfo__append(struct Array_TestInfo* self, struct TestInfo value);

#line 125 "src/std/Array.pv"
uintptr_t Array_TestInfo__prepend(struct Array_TestInfo* self, struct TestInfo value);

#line 143 "src/std/Array.pv"
bool Array_TestInfo__remove_back(struct Array_TestInfo* self);

#line 154 "src/std/Array.pv"
struct TestInfo* Array_TestInfo__back(struct Array_TestInfo* self);

#line 160 "src/std/Array.pv"
void Array_TestInfo__clear(struct Array_TestInfo* self);

#line 165 "src/std/Array.pv"
void Array_TestInfo__release(struct Array_TestInfo* self);

#line 172 "src/std/Array.pv"
struct Array_TestInfo Array_TestInfo__clone(struct Array_TestInfo* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_TestInfo Array_TestInfo__iter(struct Array_TestInfo* self);

#line 188 "src/std/Array.pv"
struct slice_TestInfo Array_TestInfo__as_slice(struct Array_TestInfo* self);

#endif
