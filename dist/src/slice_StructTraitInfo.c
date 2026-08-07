#include <slice_StructTraitInfo.h>

#include <slice_StructTraitInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_StructTraitInfo slice_StructTraitInfo__iter(struct slice_StructTraitInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_StructTraitInfo__new(self.data, self.data + self.length);
}
