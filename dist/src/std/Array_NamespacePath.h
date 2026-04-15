#ifndef PAVE_ARRAY_NAMESPACE_PATH
#define PAVE_ARRAY_NAMESPACE_PATH

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct NamespacePath;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_NamespacePath {
    struct trait_Allocator allocator;
    struct NamespacePath* data;
    uintptr_t length;
    uintptr_t capacity;
};

struct Array_NamespacePath;
struct NamespacePath;
struct NamespacePath;
#include <std/trait_Allocator.h>
#include <std/Array_NamespacePath.h>
#include <analyzer/NamespacePath.h>
#include <std/Iter_ref_NamespacePath.h>

#line 77 "src/std/Array.pv"
struct Array_NamespacePath Array_NamespacePath__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_NamespacePath Array_NamespacePath__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_NamespacePath Array_NamespacePath__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_NamespacePath__reserve(struct Array_NamespacePath* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct NamespacePath* Array_NamespacePath__get(struct Array_NamespacePath* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_NamespacePath__append(struct Array_NamespacePath* self, struct NamespacePath value);

#line 125 "src/std/Array.pv"
uintptr_t Array_NamespacePath__prepend(struct Array_NamespacePath* self, struct NamespacePath value);

#line 143 "src/std/Array.pv"
bool Array_NamespacePath__remove_back(struct Array_NamespacePath* self);

#line 154 "src/std/Array.pv"
struct NamespacePath* Array_NamespacePath__back(struct Array_NamespacePath* self);

#line 160 "src/std/Array.pv"
void Array_NamespacePath__clear(struct Array_NamespacePath* self);

#line 165 "src/std/Array.pv"
void Array_NamespacePath__release(struct Array_NamespacePath* self);

#line 172 "src/std/Array.pv"
struct Array_NamespacePath Array_NamespacePath__clone(struct Array_NamespacePath* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_NamespacePath Array_NamespacePath__iter(struct Array_NamespacePath* self);

#line 188 "src/std/Array.pv"
struct slice_NamespacePath Array_NamespacePath__as_slice(struct Array_NamespacePath* self);

#endif
