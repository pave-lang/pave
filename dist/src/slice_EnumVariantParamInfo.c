#include <slice_EnumVariantParamInfo.h>

#include <slice_EnumVariantParamInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_EnumVariantParamInfo slice_EnumVariantParamInfo__iter(struct slice_EnumVariantParamInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_EnumVariantParamInfo__new(self.data, self.data + self.length);
}
