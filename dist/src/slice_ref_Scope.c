#include <slice_ref_Scope.h>

#include <slice_ref_Scope.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Scope slice_ref_Scope__iter(struct slice_ref_Scope self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ref_Scope__new(self.data, self.data + self.length);
}
