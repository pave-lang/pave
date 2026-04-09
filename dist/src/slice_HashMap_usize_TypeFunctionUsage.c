#include <std/Iter_ref_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <stdint.h>
#include <compiler/TypeFunctionUsage.h>

#include <slice_HashMap_usize_TypeFunctionUsage.h>

#line 2 "src/std/Slice.pv"
struct Iter_ref_HashMap_usize_TypeFunctionUsage slice_HashMap_usize_TypeFunctionUsage__iter(struct slice_HashMap_usize_TypeFunctionUsage self) {
    #line 3 "src/std/Slice.pv"
    return Iter_ref_HashMap_usize_TypeFunctionUsage__new(self.data, self.data + self.length);
}
