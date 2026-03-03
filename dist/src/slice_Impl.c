#include <std/ArrayIter_ref_Impl.h>
#include <analyzer/Impl.h>
#include <stdint.h>

#include <slice_Impl.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Impl slice_Impl__iter(struct slice_Impl self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_Impl__new(self.data, self.data + self.length);
}
