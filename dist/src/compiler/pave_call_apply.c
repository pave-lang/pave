#include <stdlib.h>

#include <compiler/pave_call_apply.h>

#line 23 "src/compiler/CallTest.pv"
int32_t pave_call_apply(int32_t (*callback)(int32_t), int32_t value) {
    #line 23 "src/compiler/CallTest.pv"
    return callback(value);
}
