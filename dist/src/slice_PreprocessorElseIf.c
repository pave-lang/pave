#include <slice_PreprocessorElseIf.h>

#include <slice_PreprocessorElseIf.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_PreprocessorElseIf slice_PreprocessorElseIf__iter(struct slice_PreprocessorElseIf self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_PreprocessorElseIf__new(self.data, self.data + self.length);
}
