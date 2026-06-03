#include <slice_EnumVariantInfo.h>

#include <slice_EnumVariantInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_EnumVariantInfo slice_EnumVariantInfo__iter(struct slice_EnumVariantInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_EnumVariantInfo__new(self.data, self.data + self.length);
}
