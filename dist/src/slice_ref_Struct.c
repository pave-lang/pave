#include <slice_ref_Struct.h>

#include <slice_ref_Struct.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Struct slice_ref_Struct__iter(struct slice_ref_Struct self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ref_Struct__new(self.data, self.data + self.length);
}
