#include <slice_ptrc_char.h>

#include <slice_ptrc_char.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_ptrc_char slice_ptrc_char__iter(struct slice_ptrc_char self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_ptrc_char__new(self.data, self.data + self.length);
}
