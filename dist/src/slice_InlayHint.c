#include <std/ArrayIter_ref_InlayHint.h>
#include <analyzer/InlayHint.h>
#include <stdint.h>

#include <slice_InlayHint.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_InlayHint slice_InlayHint__iter(struct slice_InlayHint self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_InlayHint__new(self.data, self.data + self.length);
}
