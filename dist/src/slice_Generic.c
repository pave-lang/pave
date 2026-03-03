#include <std/ArrayIter_ref_Generic.h>
#include <analyzer/Generic.h>
#include <stdint.h>

#include <slice_Generic.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_Generic slice_Generic__iter(struct slice_Generic self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_Generic__new(self.data, self.data + self.length);
}
