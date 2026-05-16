#include <stdint.h>
#include <stdbool.h>

#include <assert.h>

#include <assert.h>
#include <compiler/fibonacci.h>
#include <compiler/test_FunctionCoroutine__fibonacci.test.h>

#line 1 "src/compiler/FunctionCoroutine.pv"
void test_FunctionCoroutine__fibonacci() {
    #line 33 "src/compiler/FunctionCoroutine.pv"
    uint32_t expected[8] = {0u, 1u, 1u, 2u, 3u, 5u, 8u, 13u};
    #line 34 "src/compiler/FunctionCoroutine.pv"
    uintptr_t i = 0;
    #line 35 "src/compiler/FunctionCoroutine.pv"
    { struct fibonacci __iter = (struct fibonacci) { .n = 8 };
    #line 35 "src/compiler/FunctionCoroutine.pv"
    while (fibonacci__next(&__iter)) {
        #line 35 "src/compiler/FunctionCoroutine.pv"
        uint64_t fib = fibonacci__value(&__iter);

        #line 36 "src/compiler/FunctionCoroutine.pv"
        assert(fib == expected[i]);
        #line 37 "src/compiler/FunctionCoroutine.pv"
        i += 1;
    } }
    #line 39 "src/compiler/FunctionCoroutine.pv"
    assert(i == 8);
}
