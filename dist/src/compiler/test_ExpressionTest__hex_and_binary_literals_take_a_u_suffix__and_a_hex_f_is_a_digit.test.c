#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>

#include <stdlib.h>
#include <compiler/test_ExpressionTest__hex_and_binary_literals_take_a_u_suffix__and_a_hex_f_is_a_digit.test.h>

#line 1 "src/compiler/ExpressionTest.pv"
void test_ExpressionTest__hex_and_binary_literals_take_a_u_suffix__and_a_hex_f_is_a_digit() {
    #line 16 "src/compiler/ExpressionTest.pv"
    uint32_t byte = 0xffu;
    #line 17 "src/compiler/ExpressionTest.pv"
    uint32_t mask = 0xff00u;
    #line 18 "src/compiler/ExpressionTest.pv"
    uint32_t bits = 0x5u;
    #line 20 "src/compiler/ExpressionTest.pv"
    int32_t low = 0xff;
    #line 21 "src/compiler/ExpressionTest.pv"
    if (byte != 255u || mask != 65280u || bits != 5u || low != 255) {
        #line 21 "src/compiler/ExpressionTest.pv"
        abort();
    }
}
