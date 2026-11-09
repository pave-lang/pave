#include <slice_FunctionTemp.h>

#include <slice_FunctionTemp.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_FunctionTemp slice_FunctionTemp__iter(struct slice_FunctionTemp self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_FunctionTemp__new(self.data, self.data + self.length);
}
