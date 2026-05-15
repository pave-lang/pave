#include <slice_TestInfo.h>

#include <slice_TestInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_TestInfo slice_TestInfo__iter(struct slice_TestInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_TestInfo__new(self.data, self.data + self.length);
}
