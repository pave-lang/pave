#include <std/Range_i32.h>

#include <std/Range_i32.h>

#line 25 "src/std/Range.pv"
struct Iter_i32 Range_i32__iter(struct Range_i32 self) {
    #line 26 "src/std/Range.pv"
    switch (self.type) {
        #line 27 "src/std/Range.pv"
        case RANGE__END: {
            #line 27 "src/std/Range.pv"
            int32_t end = self.end_value;
            #line 27 "src/std/Range.pv"
            return Iter_i32__new((int32_t)(0), end);
        } break;
        #line 28 "src/std/Range.pv"
        case RANGE__START_END: {
            #line 28 "src/std/Range.pv"
            int32_t start = self.startend_value._0;
            #line 28 "src/std/Range.pv"
            int32_t end = self.startend_value._1;
            #line 28 "src/std/Range.pv"
            return Iter_i32__new(start, end);
        } break;
        #line 29 "src/std/Range.pv"
        default: {
            #line 29 "src/std/Range.pv"
            return (struct Iter_i32) {};
        } break;
    }
}
