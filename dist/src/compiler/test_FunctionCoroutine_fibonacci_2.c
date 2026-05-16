#include <stdint.h>

#include <assert.h>

#include <std/Range_usize.h>
#include <compiler/test_FunctionCoroutine_fibonacci_2.h>

#line 31 "src/compiler/FunctionCoroutine.pv"
bool test_FunctionCoroutine_fibonacci_2__next(void* _ctx) {
    struct test_FunctionCoroutine_fibonacci_2* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        case 2: goto yield_2;
        default: return false;
    }

    #line 32 "src/compiler/FunctionCoroutine.pv"
    ctx->a = 0;
    #line 33 "src/compiler/FunctionCoroutine.pv"
    ctx->b = 1;

    #line 35 "src/compiler/FunctionCoroutine.pv"
    ctx->_value = 0; ctx->_state = 1; return true; yield_1:;

    #line 37 "src/compiler/FunctionCoroutine.pv"
    for (ctx->i = 1; ctx->i < ctx->n; ctx->i++) {
        #line 38 "src/compiler/FunctionCoroutine.pv"
        ctx->tmp = ctx->a + ctx->b;
        #line 39 "src/compiler/FunctionCoroutine.pv"
        ctx->a = ctx->b;
        #line 40 "src/compiler/FunctionCoroutine.pv"
        ctx->b = ctx->tmp;
        #line 41 "src/compiler/FunctionCoroutine.pv"
        ctx->_value = ctx->a; ctx->_state = 2; return true; yield_2:;
    }
    ctx->_state = -1; return false;
}
uint64_t test_FunctionCoroutine_fibonacci_2__value(void* ctx) { return ((struct test_FunctionCoroutine_fibonacci_2*)ctx)->_value; }
struct trait_Iter_u64VTable TEST_FUNCTION_COROUTINE_FIBONACCI_2__VTABLE__ITER = { .next = test_FunctionCoroutine_fibonacci_2__next, .value = test_FunctionCoroutine_fibonacci_2__value };

