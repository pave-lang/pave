#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <i32.h>
#include <compiler/PaveLowerShape.h>
#include <compiler/pave_lower_next_shape.h>

#line 35 "src/compiler/LoweringTest.pv"
struct PaveLowerShape pave_lower_next_shape(struct PaveLowerCalls* calls) {
    #line 36 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 37 "src/compiler/LoweringTest.pv"
    if (i32__Eq_i32__eq(calls->count, 1)) {
        #line 37 "src/compiler/LoweringTest.pv"
        return (struct PaveLowerShape) { .type = PAVE_LOWER_SHAPE__CIRCLE, .circle_value = 7 };
    }
    #line 38 "src/compiler/LoweringTest.pv"
    return (struct PaveLowerShape) { .type = PAVE_LOWER_SHAPE__RECT, .rect_value = { ._0 = 2, ._1 = 3} };
}
