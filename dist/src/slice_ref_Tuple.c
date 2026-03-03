#include <std/ArrayIter_ref_ref_Tuple.h>
#include <analyzer/Tuple.h>
#include <stdint.h>

#include <slice_ref_Tuple.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Tuple slice_ref_Tuple__iter(struct slice_ref_Tuple self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_ref_Tuple__new(self.data, self.data + self.length);
}
