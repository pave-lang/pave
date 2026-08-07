#include <assert.h>
#include <stdio.h>

#include <query/Query_Velocity.h>

#include <query/Query_Velocity.h>

bool Query_Velocity__run__next(void* _ctx) {
    struct Query_Velocity__run* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        default: return false;
    }

    ctx->_value = (struct tuple_u32_ptr_Velocity) { ._0 = ctx->self->flags, ._1 = 0 }; ctx->_state = 1; return true; yield_1:;
    ctx->_state = -1; return false;
}
struct tuple_u32_ptr_Velocity Query_Velocity__run__value(void* ctx) { return ((struct Query_Velocity__run*)ctx)->_value; }
struct trait_Iter_tuple_u32_ptr_VelocityVTable Query_Velocity__run__VTABLE__ITER = { .fn_next = Query_Velocity__run__next, .fn_value = Query_Velocity__run__value };

