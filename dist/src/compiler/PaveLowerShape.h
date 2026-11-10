#ifndef PAVE_PAVE_LOWER_SHAPE
#define PAVE_PAVE_LOWER_SHAPE

#include <stdint.h>

#line 10 "src/compiler/LoweringTest.pv"
struct PaveLowerShape {
    enum {
        PAVE_LOWER_SHAPE__CIRCLE,
        PAVE_LOWER_SHAPE__RECT,
        PAVE_LOWER_SHAPE__DOT,
    } type;

    union {
        int32_t circle_value;
        struct { int32_t _0; int32_t _1; } rect_value;
    };
};


#endif
