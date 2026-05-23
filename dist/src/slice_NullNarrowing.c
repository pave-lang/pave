#include <slice_NullNarrowing.h>

#include <slice_NullNarrowing.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_NullNarrowing slice_NullNarrowing__iter(struct slice_NullNarrowing self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_NullNarrowing__new(self.data, self.data + self.length);
}
