#ifndef PAVE_SLICE_SYMBOL_INFO
#define PAVE_SLICE_SYMBOL_INFO

#include <analyzer/SymbolInfo.h>
#include <std/Iter_ref_SymbolInfo.h>
struct slice_SymbolInfo { struct SymbolInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_SymbolInfo slice_SymbolInfo__iter(struct slice_SymbolInfo self);

#endif
