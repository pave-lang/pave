#include <slice_InlayHint.h>

#include <slice_InlayHint.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_InlayHint slice_InlayHint__iter(struct slice_InlayHint self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_InlayHint__new(self.data, self.data + self.length);
}
