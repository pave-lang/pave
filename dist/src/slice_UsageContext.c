#include <std/Iter_ref_UsageContext.h>
#include <compiler/UsageContext.h>
#include <stdint.h>

#include <slice_UsageContext.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_UsageContext slice_UsageContext__iter(struct slice_UsageContext self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_UsageContext__new(self.data, self.data + self.length);
}
