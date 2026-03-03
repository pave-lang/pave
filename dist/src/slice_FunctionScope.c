#include <std/ArrayIter_ref_FunctionScope.h>
#include <compiler/FunctionScope.h>
#include <stdint.h>

#include <slice_FunctionScope.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_FunctionScope slice_FunctionScope__iter(struct slice_FunctionScope self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_FunctionScope__new(self.data, self.data + self.length);
}
