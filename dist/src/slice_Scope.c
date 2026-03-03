#include <std/ArrayIter_ref_Scope.h>
#include <analyzer/Scope.h>
#include <stdint.h>

#include <slice_Scope.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Scope slice_Scope__iter(struct slice_Scope self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_Scope__new(self.data, self.data + self.length);
}
