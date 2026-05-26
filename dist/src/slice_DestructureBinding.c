#include <slice_DestructureBinding.h>

#include <slice_DestructureBinding.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_DestructureBinding slice_DestructureBinding__iter(struct slice_DestructureBinding self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_DestructureBinding__new(self.data, self.data + self.length);
}
