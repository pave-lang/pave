#include <stdint.h>

#include <std/Range_usize.h>

#include <std/Range_usize.h>

#line 25 "src/std/Range.pv"
struct Iter_usize Range_usize__iter(struct Range_usize self) {
    #line 26 "src/std/Range.pv"
    switch (self.type) {
        #line 27 "src/std/Range.pv"
        case RANGE__END: {
            #line 27 "src/std/Range.pv"
            uintptr_t end = self.end_value;
            #line 27 "src/std/Range.pv"
            return Iter_usize__new((uintptr_t)(0), end);
        } break;
        #line 28 "src/std/Range.pv"
        case RANGE__START_END: {
            #line 28 "src/std/Range.pv"
            uintptr_t start = self.startend_value._0;
            #line 28 "src/std/Range.pv"
            uintptr_t end = self.startend_value._1;
            #line 28 "src/std/Range.pv"
            return Iter_usize__new(start, end);
        } break;
        #line 29 "src/std/Range.pv"
        default: {
            #line 29 "src/std/Range.pv"
            return (struct Iter_usize) {};
        } break;
    }
}
