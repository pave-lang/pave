#include <slice_TypeImpl.h>

#include <slice_TypeImpl.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_TypeImpl slice_TypeImpl__iter(struct slice_TypeImpl self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_TypeImpl__new(self.data, self.data + self.length);
}
