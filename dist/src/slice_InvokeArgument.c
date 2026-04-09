#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <stdint.h>

#include <slice_InvokeArgument.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_InvokeArgument slice_InvokeArgument__iter(struct slice_InvokeArgument self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_InvokeArgument__new(self.data, self.data + self.length);
}
