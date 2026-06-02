#include <slice_Position.h>

#include <slice_Position.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Position slice_Position__iter(struct slice_Position self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Position__new(self.data, self.data + self.length);
}
