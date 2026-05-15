#include <slice_str.h>

#include <slice_str.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_str slice_str__iter(struct slice_str self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_str__new(self.data, self.data + self.length);
}
