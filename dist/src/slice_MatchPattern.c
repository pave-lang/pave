#include <std/Iter_ref_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>
#include <stdint.h>

#include <slice_MatchPattern.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_MatchPattern slice_MatchPattern__iter(struct slice_MatchPattern self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_MatchPattern__new(self.data, self.data + self.length);
}
