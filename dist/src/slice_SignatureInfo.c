#include <slice_SignatureInfo.h>

#include <slice_SignatureInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_SignatureInfo slice_SignatureInfo__iter(struct slice_SignatureInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_SignatureInfo__new(self.data, self.data + self.length);
}
