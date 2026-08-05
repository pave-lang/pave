#ifndef PAVE_ITER_ENUMERATE_REF_SYMBOL_INFO
#define PAVE_ITER_ENUMERATE_REF_SYMBOL_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_SymbolInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_SymbolInfo {
    uintptr_t index;
    struct Iter_ref_SymbolInfo iter;
};

#include <tuple_usize_ref_SymbolInfo.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_SymbolInfo__next(struct IterEnumerate_ref_SymbolInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_SymbolInfo IterEnumerate_ref_SymbolInfo__value(struct IterEnumerate_ref_SymbolInfo* self);

#endif
