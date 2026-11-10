#include <slice_i32.h>

#include <slice_i32.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_i32 slice_i32__iter(struct slice_i32 self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_i32__new(self.data, self.data + self.length);
}
