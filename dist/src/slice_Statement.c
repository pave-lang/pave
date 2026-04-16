#include <slice_Statement.h>

#include <slice_Statement.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Statement slice_Statement__iter(struct slice_Statement self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Statement__new(self.data, self.data + self.length);
}
