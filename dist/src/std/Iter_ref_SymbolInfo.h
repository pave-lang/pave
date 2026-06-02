#ifndef PAVE_ITER_REF_SYMBOL_INFO
#define PAVE_ITER_REF_SYMBOL_INFO

#include <stdint.h>
#include <stdbool.h>

struct SymbolInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_SymbolInfo {
    intptr_t step;
    struct SymbolInfo* iter;
    struct SymbolInfo* start;
    struct SymbolInfo* end;
};

#include <std/Iter_ref_SymbolInfo.h>
#include <std/IterEnumerate_ref_SymbolInfo.h>
struct SymbolInfo;
struct Iter_ref_SymbolInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_SymbolInfo Iter_ref_SymbolInfo__new(struct SymbolInfo* start, struct SymbolInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_SymbolInfo Iter_ref_SymbolInfo__reverse(struct Iter_ref_SymbolInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_SymbolInfo Iter_ref_SymbolInfo__skip(struct Iter_ref_SymbolInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_SymbolInfo__next(struct Iter_ref_SymbolInfo* self);

#line 43 "src/std/Array.pv"
struct SymbolInfo* Iter_ref_SymbolInfo__value(struct Iter_ref_SymbolInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_SymbolInfo Iter_ref_SymbolInfo__enumerate(struct Iter_ref_SymbolInfo self);

#endif
