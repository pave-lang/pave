#include <slice_CompletionInfo.h>

#include <slice_CompletionInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_CompletionInfo slice_CompletionInfo__iter(struct slice_CompletionInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_CompletionInfo__new(self.data, self.data + self.length);
}
