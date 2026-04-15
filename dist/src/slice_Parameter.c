#include <slice_Parameter.h>

#include <slice_Parameter.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Parameter slice_Parameter__iter(struct slice_Parameter self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Parameter__new(self.data, self.data + self.length);
}
