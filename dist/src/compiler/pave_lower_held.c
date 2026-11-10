#include <stdint.h>

#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <compiler/PaveLowerHolder.h>
#include <compiler/pave_lower_held.h>

#line 41 "src/compiler/LoweringTest.pv"
struct PaveLowerHolder* pave_lower_held(struct PaveLowerHolder* holder, struct PaveLowerCalls* calls) {
    #line 42 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 43 "src/compiler/LoweringTest.pv"
    return holder;
}
