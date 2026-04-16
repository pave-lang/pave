#include <slice_NamespacePath.h>

#include <slice_NamespacePath.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_NamespacePath slice_NamespacePath__iter(struct slice_NamespacePath self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_NamespacePath__new(self.data, self.data + self.length);
}
