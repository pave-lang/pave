#ifndef PAVE_RANGE_USIZE
#define PAVE_RANGE_USIZE

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

struct Range_usize {
    enum Range__Type type;
    union {
        uintptr_t start_value;
        uintptr_t end_value;
        struct { uintptr_t _0; uintptr_t _1; } startend_value;
    };
};

#include <std/Range_usize.h>
#include <std/Iter_usize.h>

#line 25 "src/std/Range.pv"
struct Iter_usize Range_usize__iter(struct Range_usize self);

#endif
