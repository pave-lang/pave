#include <stdint.h>

#include <std/Range_ptrc_char.h>

#include <std/Range_ptrc_char.h>

#line 25 "src/std/Range.pv"
struct Iter_ptrc_char Range_ptrc_char__iter(struct Range_ptrc_char self) {
    #line 26 "src/std/Range.pv"
    switch (self.type) {
        #line 27 "src/std/Range.pv"
        case RANGE__END: {
            #line 27 "src/std/Range.pv"
            char const* end = self.end_value;
            #line 27 "src/std/Range.pv"
            return Iter_ptrc_char__new((char const*)(0), end);
        } break;
        #line 28 "src/std/Range.pv"
        case RANGE__START_END: {
            #line 28 "src/std/Range.pv"
            char const* start = self.startend_value._0;
            #line 28 "src/std/Range.pv"
            char const* end = self.startend_value._1;
            #line 28 "src/std/Range.pv"
            return Iter_ptrc_char__new(start, end);
        } break;
        #line 29 "src/std/Range.pv"
        default: {
            #line 29 "src/std/Range.pv"
            return (struct Iter_ptrc_char) {};
        } break;
    }
}
