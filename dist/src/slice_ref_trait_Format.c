#include <slice_ref_trait_Format.h>

#include <slice_ref_trait_Format.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_trait_Format slice_ref_trait_Format__iter(struct slice_ref_trait_Format self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ref_trait_Format__new(self.data, self.data + self.length);
}
