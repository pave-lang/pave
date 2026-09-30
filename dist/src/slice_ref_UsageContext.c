#include <slice_ref_UsageContext.h>

#include <slice_ref_UsageContext.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_UsageContext slice_ref_UsageContext__iter(struct slice_ref_UsageContext self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ref_UsageContext__new(self.data, self.data + self.length);
}
