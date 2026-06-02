#include <slice_SymbolInfo.h>

#include <slice_SymbolInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_SymbolInfo slice_SymbolInfo__iter(struct slice_SymbolInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_SymbolInfo__new(self.data, self.data + self.length);
}
