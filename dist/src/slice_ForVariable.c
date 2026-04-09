#include <std/Iter_ref_ForVariable.h>
#include <analyzer/statement/ForVariable.h>
#include <stdint.h>

#include <slice_ForVariable.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ForVariable slice_ForVariable__iter(struct slice_ForVariable self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ForVariable__new(self.data, self.data + self.length);
}
