#ifndef PAVE_ARRAY_SIGNATURE_INFO
#define PAVE_ARRAY_SIGNATURE_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct SignatureInfo;

#line 69 "src/std/Array.pv"
struct Array_SignatureInfo {
    struct trait_Allocator allocator;
    struct SignatureInfo* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <analyzer/SignatureInfo.h>
#include <std/Iter_ref_SignatureInfo.h>
#include <slice_SignatureInfo.h>
struct SignatureInfo;

#line 77 "src/std/Array.pv"
struct Array_SignatureInfo Array_SignatureInfo__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_SignatureInfo Array_SignatureInfo__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_SignatureInfo Array_SignatureInfo__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_SignatureInfo__reserve(struct Array_SignatureInfo* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct SignatureInfo* Array_SignatureInfo__get(struct Array_SignatureInfo* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_SignatureInfo__append(struct Array_SignatureInfo* self, struct SignatureInfo value);

#line 125 "src/std/Array.pv"
uintptr_t Array_SignatureInfo__prepend(struct Array_SignatureInfo* self, struct SignatureInfo value);

#line 143 "src/std/Array.pv"
bool Array_SignatureInfo__remove_back(struct Array_SignatureInfo* self);

#line 154 "src/std/Array.pv"
struct SignatureInfo* Array_SignatureInfo__back(struct Array_SignatureInfo* self);

#line 160 "src/std/Array.pv"
void Array_SignatureInfo__clear(struct Array_SignatureInfo* self);

#line 165 "src/std/Array.pv"
void Array_SignatureInfo__release(struct Array_SignatureInfo* self);

#line 172 "src/std/Array.pv"
struct Array_SignatureInfo Array_SignatureInfo__clone(struct Array_SignatureInfo* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_SignatureInfo Array_SignatureInfo__iter(struct Array_SignatureInfo* self);

#line 188 "src/std/Array.pv"
struct slice_SignatureInfo Array_SignatureInfo__as_slice(struct Array_SignatureInfo* self);

#line 195 "src/std/Array.pv"
struct SignatureInfo* Array_SignatureInfo__Index__index(void* __self);


#endif
