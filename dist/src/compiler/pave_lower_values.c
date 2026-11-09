#include <stdint.h>

#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <slice_i32.h>
#include <compiler/pave_lower_values.h>

#line 72 "src/compiler/LoweringTest.pv"
struct slice_i32 pave_lower_values(struct slice_i32 values, struct PaveLowerCalls* calls) {
    #line 73 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 74 "src/compiler/LoweringTest.pv"
    return values;
}
