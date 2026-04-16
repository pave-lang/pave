#include <slice_MatchCase.h>

#include <slice_MatchCase.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_MatchCase slice_MatchCase__iter(struct slice_MatchCase self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_MatchCase__new(self.data, self.data + self.length);
}
