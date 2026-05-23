#include <slice_StructFieldInfo.h>

#include <slice_StructFieldInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_StructFieldInfo slice_StructFieldInfo__iter(struct slice_StructFieldInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_StructFieldInfo__new(self.data, self.data + self.length);
}
