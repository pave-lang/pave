#ifndef PAVE_ARRAY_IMPL_NODE
#define PAVE_ARRAY_IMPL_NODE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct ImplNode;

#line 69 "src/std/Array.pv"
struct Array_ImplNode {
    struct trait_Allocator allocator;
    struct ImplNode* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <std/Iter_ref_ImplNode.h>
#include <slice_ImplNode.h>
struct Array_ImplNode;
struct ImplNode;

#line 77 "src/std/Array.pv"
struct Array_ImplNode Array_ImplNode__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ImplNode Array_ImplNode__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ImplNode Array_ImplNode__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ImplNode__reserve(struct Array_ImplNode* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct ImplNode* Array_ImplNode__get(struct Array_ImplNode* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ImplNode__append(struct Array_ImplNode* self, struct ImplNode value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ImplNode__prepend(struct Array_ImplNode* self, struct ImplNode value);

#line 143 "src/std/Array.pv"
bool Array_ImplNode__remove_back(struct Array_ImplNode* self);

#line 154 "src/std/Array.pv"
struct ImplNode* Array_ImplNode__back(struct Array_ImplNode* self);

#line 160 "src/std/Array.pv"
void Array_ImplNode__clear(struct Array_ImplNode* self);

#line 165 "src/std/Array.pv"
void Array_ImplNode__release(struct Array_ImplNode* self);

#line 172 "src/std/Array.pv"
struct Array_ImplNode Array_ImplNode__clone(struct Array_ImplNode* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_ImplNode Array_ImplNode__iter(struct Array_ImplNode* self);

#line 188 "src/std/Array.pv"
struct slice_ImplNode Array_ImplNode__as_slice(struct Array_ImplNode* self);

#endif
