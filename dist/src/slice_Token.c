#include <std/Iter_ref_Token.h>
#include <analyzer/Token.h>
#include <stdint.h>

#include <slice_Token.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_Token slice_Token__iter(struct slice_Token self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_Token__new(self.data, self.data + self.length);
}
