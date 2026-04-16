#include <slice_TypeId.h>

#include <slice_TypeId.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_TypeId slice_TypeId__iter(struct slice_TypeId self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_TypeId__new(self.data, self.data + self.length);
}
