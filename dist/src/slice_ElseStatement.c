#include <std/ArrayIter_ref_ElseStatement.h>
#include <analyzer/ElseStatement.h>
#include <stdint.h>

#include <slice_ElseStatement.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ElseStatement slice_ElseStatement__iter(struct slice_ElseStatement self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_ElseStatement__new(self.data, self.data + self.length);
}
