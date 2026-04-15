#include <slice_String.h>

#include <slice_String.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_String slice_String__iter(struct slice_String self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_String__new(self.data, self.data + self.length);
}
