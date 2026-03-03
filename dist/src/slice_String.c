#include <std/ArrayIter_ref_String.h>
#include <std/String.h>
#include <stdint.h>

#include <slice_String.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_String slice_String__iter(struct slice_String self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_String__new(self.data, self.data + self.length);
}
