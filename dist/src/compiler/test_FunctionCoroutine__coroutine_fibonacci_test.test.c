#include <stdint.h>
#include <stdbool.h>

#include <assert.h>

#include <assert.h>
#include <compiler/test_FunctionCoroutine_fibonacci_1.h>
#include <compiler/test_FunctionCoroutine_fibonacci_2.h>
#include <compiler/test_FunctionCoroutine__coroutine_fibonacci_test.test.h>

#line 1 "src/compiler/FunctionCoroutine.pv"
void test_FunctionCoroutine__coroutine_fibonacci_test() {
    #line 47 "src/compiler/FunctionCoroutine.pv"
    uint32_t expected[8] = {0u, 1u, 1u, 2u, 3u, 5u, 8u, 13u};
    #line 48 "src/compiler/FunctionCoroutine.pv"
    uintptr_t i = 0;
    #line 49 "src/compiler/FunctionCoroutine.pv"
    { struct test_FunctionCoroutine_fibonacci_1 __iter = (struct test_FunctionCoroutine_fibonacci_1) { .n = 8 };
    #line 49 "src/compiler/FunctionCoroutine.pv"
    while (test_FunctionCoroutine_fibonacci_1__next(&__iter)) {
        #line 49 "src/compiler/FunctionCoroutine.pv"
        uint64_t fib = test_FunctionCoroutine_fibonacci_1__value(&__iter);

        #line 50 "src/compiler/FunctionCoroutine.pv"
        assert(fib == expected[i]);
        #line 51 "src/compiler/FunctionCoroutine.pv"
        i += 1;
    } }

    #line 54 "src/compiler/FunctionCoroutine.pv"
    i = 0;
    #line 55 "src/compiler/FunctionCoroutine.pv"
    { struct test_FunctionCoroutine_fibonacci_2 __iter = (struct test_FunctionCoroutine_fibonacci_2) { .n = 8 };
    #line 55 "src/compiler/FunctionCoroutine.pv"
    while (test_FunctionCoroutine_fibonacci_2__next(&__iter)) {
        #line 55 "src/compiler/FunctionCoroutine.pv"
        uint64_t fib = test_FunctionCoroutine_fibonacci_2__value(&__iter);

        #line 56 "src/compiler/FunctionCoroutine.pv"
        assert(fib == expected[i]);
        #line 57 "src/compiler/FunctionCoroutine.pv"
        i += 1;
    } }

    #line 60 "src/compiler/FunctionCoroutine.pv"
    assert(i == 8);
}
