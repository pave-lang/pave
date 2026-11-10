#include <stdlib.h>

#include <tuple_i32_i32.h>
#include <compiler/pave_call_pair.h>
#include <compiler/pave_call_wrap.h>

#line 19 "src/compiler/CallTest.pv"
struct tuple_i32_i32 pave_call_wrap(int32_t a, int32_t b) {
    #line 19 "src/compiler/CallTest.pv"
    return pave_call_pair(a, b);
}
