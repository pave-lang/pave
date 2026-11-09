#include <stdint.h>

#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <compiler/PaveLowerNode.h>
#include <compiler/pave_lower_find.h>

#line 58 "src/compiler/LoweringTest.pv"
struct PaveLowerNode* pave_lower_find(struct PaveLowerNode* node, struct PaveLowerCalls* calls) {
    #line 59 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 60 "src/compiler/LoweringTest.pv"
    return node;
}
