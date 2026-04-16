#include <slice_Impl.h>

#include <slice_Impl.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Impl slice_Impl__iter(struct slice_Impl self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Impl__new(self.data, self.data + self.length);
}
