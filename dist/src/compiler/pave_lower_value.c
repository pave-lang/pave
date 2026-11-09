#include <stdlib.h>

#include <compiler/PaveLowerNode.h>
#include <compiler/pave_lower_find.h>
#include <compiler/PaveLowerCalls.h>
#include <compiler/pave_lower_value.h>

#line 63 "src/compiler/LoweringTest.pv"
int32_t* pave_lower_value(struct PaveLowerNode* node, struct PaveLowerCalls* calls) {
    struct PaveLowerNode* __pave_tmp_0;

    #line 64 "src/compiler/LoweringTest.pv"
    return ((__pave_tmp_0 = pave_lower_find(node, calls)) == 0 ? 0 : PaveLowerNode__get(__pave_tmp_0));
}
