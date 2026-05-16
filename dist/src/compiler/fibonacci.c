#include <stdint.h>

#include <assert.h>

#include <std/Range_usize.h>
#include <compiler/fibonacci.h>

#line 19 "src/compiler/FunctionCoroutine.pv"
bool fibonacci__next(void* _ctx) {
    struct fibonacci* ctx = _ctx;
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
        ctx->value = ctx->a;
        #line 25 "src/compiler/FunctionCoroutine.pv"
        ctx->tmp = ctx->a + ctx->b;
        #line 26 "src/compiler/FunctionCoroutine.pv"
        ctx->a = ctx->b;
        #line 27 "src/compiler/FunctionCoroutine.pv"
        ctx->b = ctx->tmp;
        #line 28 "src/compiler/FunctionCoroutine.pv"
        ctx->_value = ctx->value; ctx->_state = 1; return true; yield_1:;
    }
    ctx->_state = -1; return false;
}
uint64_t fibonacci__value(void* ctx) { return ((struct fibonacci*)ctx)->_value; }
struct trait_Iter_u64VTable FIBONACCI__VTABLE__ITER = { .next = fibonacci__next, .value = fibonacci__value };

