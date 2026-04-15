#include <slice_char.h>

#include <slice_char.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_char slice_char__iter(struct slice_char self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_char__new(self.data, self.data + self.length);
}
