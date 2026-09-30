#include <slice_Array_u32.h>

#include <slice_Array_u32.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Array_u32 slice_Array_u32__iter(struct slice_Array_u32 self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Array_u32__new(self.data, self.data + self.length);
}
