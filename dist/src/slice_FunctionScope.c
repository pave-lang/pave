#include <slice_FunctionScope.h>

#include <slice_FunctionScope.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_FunctionScope slice_FunctionScope__iter(struct slice_FunctionScope self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_FunctionScope__new(self.data, self.data + self.length);
}
