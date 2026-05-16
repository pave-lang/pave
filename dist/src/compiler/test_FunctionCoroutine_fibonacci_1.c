#include <stdint.h>

#include <assert.h>

#include <std/Range_usize.h>
#include <compiler/test_FunctionCoroutine_fibonacci_1.h>

#line 19 "src/compiler/FunctionCoroutine.pv"
bool test_FunctionCoroutine_fibonacci_1__next(void* _ctx) {
    struct test_FunctionCoroutine_fibonacci_1* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        default: return false;
    }

    #line 20 "src/compiler/FunctionCoroutine.pv"
    ctx->a = 0;
    #line 21 "src/compiler/FunctionCoroutine.pv"
    ctx->b = 1;

    #line 23 "src/compiler/FunctionCoroutine.pv"
    for (ctx->i = 0; ctx->i < ctx->n; ctx->i++) {
        #line 24 "src/compiler/FunctionCoroutine.pv"
        ctx->_value = ctx->a; ctx->_state = 1; return true; yield_1:;
        #line 25 "src/compiler/FunctionCoroutine.pv"
        ctx->tmp = ctx->a + ctx->b;
        #line 26 "src/compiler/FunctionCoroutine.pv"
        ctx->a = ctx->b;
        #line 27 "src/compiler/FunctionCoroutine.pv"
        ctx->b = ctx->tmp;
    }
    ctx->_state = -1; return false;
}
uint64_t test_FunctionCoroutine_fibonacci_1__value(void* ctx) { return ((struct test_FunctionCoroutine_fibonacci_1*)ctx)->_value; }
struct trait_Iter_u64VTable TEST_FUNCTION_COROUTINE_FIBONACCI_1__VTABLE__ITER = { .next = test_FunctionCoroutine_fibonacci_1__next, .value = test_FunctionCoroutine_fibonacci_1__value };

