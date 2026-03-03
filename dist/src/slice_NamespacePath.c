#include <std/ArrayIter_ref_NamespacePath.h>
#include <analyzer/NamespacePath.h>
#include <stdint.h>

#include <slice_NamespacePath.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_NamespacePath slice_NamespacePath__iter(struct slice_NamespacePath self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_NamespacePath__new(self.data, self.data + self.length);
}
