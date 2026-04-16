#include <slice_tuple_usize_str_TypeId.h>

#include <slice_tuple_usize_str_TypeId.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_tuple_usize_str_TypeId slice_tuple_usize_str_TypeId__iter(struct slice_tuple_usize_str_TypeId self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_tuple_usize_str_TypeId__new(self.data, self.data + self.length);
}
