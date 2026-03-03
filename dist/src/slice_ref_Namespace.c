#include <std/ArrayIter_ref_ref_Namespace.h>
#include <analyzer/Namespace.h>
#include <stdint.h>

#include <slice_ref_Namespace.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Namespace slice_ref_Namespace__iter(struct slice_ref_Namespace self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_ref_Namespace__new(self.data, self.data + self.length);
}
