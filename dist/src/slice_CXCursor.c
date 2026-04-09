#include <std/Iter_ref_CXCursor.h>
#include <stdint.h>

#include <slice_CXCursor.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_CXCursor slice_CXCursor__iter(struct slice_CXCursor self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_CXCursor__new(self.data, self.data + self.length);
}
