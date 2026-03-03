#include <std/ArrayIter_ref_TypeImpl.h>
#include <analyzer/TypeImpl.h>
#include <stdint.h>

#include <slice_TypeImpl.h>

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_TypeImpl slice_TypeImpl__iter(struct slice_TypeImpl self) {
    #line 3 "src/std/Slice.pv"
    return ArrayIter_ref_TypeImpl__new(self.data, self.data + self.length);
}
