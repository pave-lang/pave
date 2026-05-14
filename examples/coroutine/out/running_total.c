#include <stdint.h>

#include <stdio.h>

#include <std/Range_usize.h>
#include <coroutine/running_total.h>

bool running_total__next(void* _ctx) {
    struct running_total* ctx = _ctx;
    switch (ctx->_state) {
case 0: break;
        case 1: goto yield_1;
        case 2: goto yield_2;
        default: return false;
    }

    ctx->total = 0.0f;

    for (ctx->i = 0; ctx->i < ctx->steps; ctx->i++) {
        ctx->_value = ctx->total; ctx->_state = 1; return true; yield_1:

        ctx->total += ctx->increment;
    }

    ctx->_value = ctx->total; ctx->_state = 2; return true; yield_2:
    ctx->_state = -1; return false;
}
float running_total__value(void* ctx) { return ((struct running_total*)ctx)->_value; }
struct trait_Iter_f32VTable RUNNING_TOTAL__VTABLE__ITER = { .next = running_total__next, .value = running_total__value };

