#ifndef PAVE_ARRAY_REF_GENERIC_MAP
#define PAVE_ARRAY_REF_GENERIC_MAP

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct GenericMap;
struct ArrayIter_ref_ref_GenericMap;

#include <stdlib.h>
#include <string.h>

#line 69 "src/std/Array.pv"
struct Array_ref_GenericMap {
    struct Allocator allocator;
    struct GenericMap** data;
    uintptr_t length;
    uintptr_t capacity;
};

#line 77 "src/std/Array.pv"
struct Array_ref_GenericMap Array_ref_GenericMap__new(struct Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_ref_GenericMap Array_ref_GenericMap__new_with_length(struct Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_ref_GenericMap Array_ref_GenericMap__new_with_capacity(struct Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_ref_GenericMap__reserve(struct Array_ref_GenericMap* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct GenericMap** Array_ref_GenericMap__get(struct Array_ref_GenericMap* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_ref_GenericMap__append(struct Array_ref_GenericMap* self, struct GenericMap* value);

#line 125 "src/std/Array.pv"
uintptr_t Array_ref_GenericMap__prepend(struct Array_ref_GenericMap* self, struct GenericMap* value);

#line 143 "src/std/Array.pv"
bool Array_ref_GenericMap__remove_back(struct Array_ref_GenericMap* self);

#line 154 "src/std/Array.pv"
struct GenericMap** Array_ref_GenericMap__back(struct Array_ref_GenericMap* self);

#line 160 "src/std/Array.pv"
void Array_ref_GenericMap__clear(struct Array_ref_GenericMap* self);

#line 165 "src/std/Array.pv"
void Array_ref_GenericMap__release(struct Array_ref_GenericMap* self);

#line 172 "src/std/Array.pv"
struct Array_ref_GenericMap Array_ref_GenericMap__clone(struct Array_ref_GenericMap* self, struct Allocator allocator);

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_ref_GenericMap Array_ref_GenericMap__iter(struct Array_ref_GenericMap* self);

#line 188 "src/std/Array.pv"
struct slice_ref_GenericMap Array_ref_GenericMap__as_slice(struct Array_ref_GenericMap* self);

#endif
