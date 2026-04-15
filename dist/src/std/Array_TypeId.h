#ifndef PAVE_ARRAY_TYPE_ID
#define PAVE_ARRAY_TYPE_ID

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

typedef uint64_t TypeId;
#include <std/trait_Allocator.h>

#line 69 "src/std/Array.pv"
struct Array_TypeId {
    struct trait_Allocator allocator;
    TypeId* data;
    uintptr_t length;
    uintptr_t capacity;
};
struct Array_TypeId;
typedef uint64_t TypeId;
typedef uint64_t TypeId;
#include <std/trait_Allocator.h>
#include <std/Array_TypeId.h>
#include <std/TypeId.h>
#include <std/Iter_ref_TypeId.h>


#line 77 "src/std/Array.pv"
struct Array_TypeId Array_TypeId__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_TypeId Array_TypeId__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_TypeId Array_TypeId__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_TypeId__reserve(struct Array_TypeId* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
TypeId* Array_TypeId__get(struct Array_TypeId* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_TypeId__append(struct Array_TypeId* self, TypeId value);

#line 125 "src/std/Array.pv"
uintptr_t Array_TypeId__prepend(struct Array_TypeId* self, TypeId value);

#line 143 "src/std/Array.pv"
bool Array_TypeId__remove_back(struct Array_TypeId* self);

#line 154 "src/std/Array.pv"
TypeId* Array_TypeId__back(struct Array_TypeId* self);

#line 160 "src/std/Array.pv"
void Array_TypeId__clear(struct Array_TypeId* self);

#line 165 "src/std/Array.pv"
void Array_TypeId__release(struct Array_TypeId* self);

#line 172 "src/std/Array.pv"
struct Array_TypeId Array_TypeId__clone(struct Array_TypeId* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_TypeId Array_TypeId__iter(struct Array_TypeId* self);

#line 188 "src/std/Array.pv"
struct slice_TypeId Array_TypeId__as_slice(struct Array_TypeId* self);

#endif
