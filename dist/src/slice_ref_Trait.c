#include <std/ArrayIter_ref_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <stdint.h>

#include <slice_ref_Trait.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_ref_Trait slice_ref_Trait__iter(struct slice_ref_Trait self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_ref_Trait__new(self.data, self.data + self.length);
}
