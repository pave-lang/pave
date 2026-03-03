#include <std/ArrayIter_ref_ref_Expression.h>
#include <analyzer/Expression.h>
#include <stdint.h>

#include <slice_ref_Expression.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Expression slice_ref_Expression__iter(struct slice_ref_Expression self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_ref_Expression__new(self.data, self.data + self.length);
}
