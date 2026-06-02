#ifndef PAVE_ARRAY_SYMBOL_INFO
#define PAVE_ARRAY_SYMBOL_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct SymbolInfo;

#line 69 "src/std/Array.pv"
struct Array_SymbolInfo {
    struct trait_Allocator allocator;
    struct SymbolInfo* data;
    uintptr_t length;
    uintptr_t capacity;
};

#include <std/trait_Allocator.h>
#include <std/Array_SymbolInfo.h>
#include <analyzer/SymbolInfo.h>
#include <std/Iter_ref_SymbolInfo.h>
#include <slice_SymbolInfo.h>
struct Array_SymbolInfo;
struct SymbolInfo;

#line 77 "src/std/Array.pv"
struct Array_SymbolInfo Array_SymbolInfo__new(struct trait_Allocator allocator);

#line 81 "src/std/Array.pv"
struct Array_SymbolInfo Array_SymbolInfo__new_with_length(struct trait_Allocator allocator, uintptr_t length);

#line 88 "src/std/Array.pv"
struct Array_SymbolInfo Array_SymbolInfo__new_with_capacity(struct trait_Allocator allocator, uintptr_t length);

#line 94 "src/std/Array.pv"
void Array_SymbolInfo__reserve(struct Array_SymbolInfo* self, uintptr_t capacity);

#line 103 "src/std/Array.pv"
struct SymbolInfo* Array_SymbolInfo__get(struct Array_SymbolInfo* self, uintptr_t index);

#line 108 "src/std/Array.pv"
uintptr_t Array_SymbolInfo__append(struct Array_SymbolInfo* self, struct SymbolInfo value);

#line 125 "src/std/Array.pv"
uintptr_t Array_SymbolInfo__prepend(struct Array_SymbolInfo* self, struct SymbolInfo value);

#line 143 "src/std/Array.pv"
bool Array_SymbolInfo__remove_back(struct Array_SymbolInfo* self);

#line 154 "src/std/Array.pv"
struct SymbolInfo* Array_SymbolInfo__back(struct Array_SymbolInfo* self);

#line 160 "src/std/Array.pv"
void Array_SymbolInfo__clear(struct Array_SymbolInfo* self);

#line 165 "src/std/Array.pv"
void Array_SymbolInfo__release(struct Array_SymbolInfo* self);

#line 172 "src/std/Array.pv"
struct Array_SymbolInfo Array_SymbolInfo__clone(struct Array_SymbolInfo* self, struct trait_Allocator allocator);

#line 184 "src/std/Array.pv"
struct Iter_ref_SymbolInfo Array_SymbolInfo__iter(struct Array_SymbolInfo* self);

#line 188 "src/std/Array.pv"
struct slice_SymbolInfo Array_SymbolInfo__as_slice(struct Array_SymbolInfo* self);

#line 195 "src/std/Array.pv"
struct SymbolInfo* Array_SymbolInfo__Index__index(void* __self);


#endif
