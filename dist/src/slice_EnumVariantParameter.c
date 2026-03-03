#include <std/ArrayIter_ref_EnumVariantParameter.h>
#include <analyzer/EnumVariantParameter.h>
#include <stdint.h>

#include <slice_EnumVariantParameter.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_EnumVariantParameter slice_EnumVariantParameter__iter(struct slice_EnumVariantParameter self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_EnumVariantParameter__new(self.data, self.data + self.length);
}
