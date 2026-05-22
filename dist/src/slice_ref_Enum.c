#include <slice_ref_Enum.h>

#include <slice_ref_Enum.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Enum slice_ref_Enum__iter(struct slice_ref_Enum self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ref_Enum__new(self.data, self.data + self.length);
}
