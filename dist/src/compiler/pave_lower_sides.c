#include <stdlib.h>

#include <compiler/pave_lower_sides.h>

#line 83 "src/compiler/LoweringTest.pv"
bool pave_lower_sides__next(void* _ctx) {
    struct pave_lower_sides* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        case 2: goto yield_2;
        case 3: goto yield_3;
        default: return false;
    }

    #line 84 "src/compiler/LoweringTest.pv"
    switch (ctx->shape.type) {
        #line 85 "src/compiler/LoweringTest.pv"
        case PAVE_LOWER_SHAPE__RECT: {
            #line 85 "src/compiler/LoweringTest.pv"
            ctx->w = ctx->shape.rect_value._0;
            #line 85 "src/compiler/LoweringTest.pv"
            ctx->h = ctx->shape.rect_value._1;
            #line 86 "src/compiler/LoweringTest.pv"
            ctx->_value = ctx->w; ctx->_state = 1; return true; yield_1:;
            #line 87 "src/compiler/LoweringTest.pv"
            ctx->_value = ctx->h; ctx->_state = 2; return true; yield_2:;
            #line 88 "src/compiler/LoweringTest.pv"
            ctx->_value = ctx->w * ctx->h; ctx->_state = 3; return true; yield_3:;
        } break;
        #line 90 "src/compiler/LoweringTest.pv"
        default: {
        } break;
    }
    ctx->_state = -1; return false;
}
int32_t pave_lower_sides__value(void* ctx) { return ((struct pave_lower_sides*)ctx)->_value; }
struct trait_Iter_i32VTable pave_lower_sides__VTABLE__ITER = { .fn_next = pave_lower_sides__next, .fn_value = pave_lower_sides__value };

