#include <std/Iter_ref_Type.h>
#include <analyzer/types/Type.h>
#include <stdint.h>

#include <slice_Type.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Type slice_Type__iter(struct slice_Type self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Type__new(self.data, self.data + self.length);
}
