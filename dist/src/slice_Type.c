#include <std/ArrayIter_ref_Type.h>
#include <analyzer/Type.h>
#include <stdint.h>

#include <slice_Type.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Type slice_Type__iter(struct slice_Type self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_Type__new(self.data, self.data + self.length);
}
