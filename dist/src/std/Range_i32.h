#ifndef PAVE_RANGE_I32
#define PAVE_RANGE_I32

#include <stdint.h>

#line 1 "src/std/Range.pv"
#ifndef PAVE_RANGE__TYPE
#define PAVE_RANGE__TYPE
enum Range__Type {
    RANGE__ALL,
    RANGE__START,
    RANGE__END,
    RANGE__START_END,
};
#endif

struct Range_i32 {
    enum Range__Type type;
    union {
        int32_t start_value;
        int32_t end_value;
        struct { int32_t _0; int32_t _1; } startend_value;
    };
};

#include <std/Range_i32.h>
#include <std/Iter_i32.h>

#line 25 "src/std/Range.pv"
struct Iter_i32 Range_i32__iter(struct Range_i32 self);

#endif
