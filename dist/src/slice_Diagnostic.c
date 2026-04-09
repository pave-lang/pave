#include <std/Iter_ref_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <stdint.h>

#include <slice_Diagnostic.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Diagnostic slice_Diagnostic__iter(struct slice_Diagnostic self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Diagnostic__new(self.data, self.data + self.length);
}
