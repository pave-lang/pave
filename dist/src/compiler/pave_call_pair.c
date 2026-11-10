#include <stdlib.h>

#include <tuple_i32_i32.h>
#include <compiler/pave_call_pair.h>

#line 17 "src/compiler/CallTest.pv"
struct tuple_i32_i32 pave_call_pair(int32_t a, int32_t b) {
    #line 17 "src/compiler/CallTest.pv"
    return (struct tuple_i32_i32) { ._0 = b * 10, ._1 = a * 10 };
}
