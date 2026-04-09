#include <std/Iter_ref_ref_GenericMap.h>
#include <analyzer/types/GenericMap.h>
#include <stdint.h>

#include <slice_ref_GenericMap.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_GenericMap slice_ref_GenericMap__iter(struct slice_ref_GenericMap self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ref_GenericMap__new(self.data, self.data + self.length);
}
