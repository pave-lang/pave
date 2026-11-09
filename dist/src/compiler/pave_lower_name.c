#include <stdint.h>

#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <compiler/pave_lower_name.h>

#line 46 "src/compiler/LoweringTest.pv"
char const* pave_lower_name(struct PaveLowerCalls* calls) {
    #line 47 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 48 "src/compiler/LoweringTest.pv"
    return "abc";
}
