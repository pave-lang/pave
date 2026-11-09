#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <compiler/pave_lower_limit.h>

#line 67 "src/compiler/LoweringTest.pv"
int32_t pave_lower_limit(struct PaveLowerCalls* calls) {
    #line 68 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 69 "src/compiler/LoweringTest.pv"
    return 3;
}
