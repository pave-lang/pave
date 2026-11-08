#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <assert.h>

#include <assert.h>
#include <i32.h>
#include <tests/test_tests__basic_arithmetic.h>

void test_tests__basic_arithmetic() {
    int32_t x = 1 + 2;
    assert(i32__Eq_i32__eq(x, 3));
}
