#include <std/Iter_ref_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <stdint.h>

#include <slice_ImplNode.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ImplNode slice_ImplNode__iter(struct slice_ImplNode self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ImplNode__new(self.data, self.data + self.length);
}
