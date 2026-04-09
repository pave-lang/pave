#include <std/Iter_ref_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <stdint.h>

#include <slice_DeferStatement.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_DeferStatement slice_DeferStatement__iter(struct slice_DeferStatement self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_DeferStatement__new(self.data, self.data + self.length);
}
