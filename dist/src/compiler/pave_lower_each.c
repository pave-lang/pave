#include <stdlib.h>

#include <compiler/pave_lower_each.h>

#line 77 "src/compiler/LoweringTest.pv"
bool pave_lower_each__next(void* _ctx) {
    struct pave_lower_each* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        default: return false;
    }

    #line 78 "src/compiler/LoweringTest.pv"
    for (ctx->__iter = 0; ctx->__iter < ctx->items.length; ctx->__iter++) {
        #line 78 "src/compiler/LoweringTest.pv"
        ctx->item = ctx->items.data[ctx->__iter];

        #line 79 "src/compiler/LoweringTest.pv"
        ctx->_value = ctx->item; ctx->_state = 1; return true; yield_1:;
    }
    ctx->_state = -1; return false;
}
int32_t pave_lower_each__value(void* ctx) { return ((struct pave_lower_each*)ctx)->_value; }
struct trait_Iter_i32VTable pave_lower_each__VTABLE__ITER = { .fn_next = pave_lower_each__next, .fn_value = pave_lower_each__value };

