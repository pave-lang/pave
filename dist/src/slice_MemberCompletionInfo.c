#include <slice_MemberCompletionInfo.h>

#include <slice_MemberCompletionInfo.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_MemberCompletionInfo slice_MemberCompletionInfo__iter(struct slice_MemberCompletionInfo self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_MemberCompletionInfo__new(self.data, self.data + self.length);
}
