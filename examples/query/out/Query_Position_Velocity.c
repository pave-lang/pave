#include <stdint.h>

#include <assert.h>
#include <stdio.h>

#include <tuple_u32_ptr_Position_ptr_Velocity.h>
#include <query/Query_Position_Velocity.h>
#include <query/Query_Position_Velocity.h>

#include <query/Query_Position_Velocity.h>

bool Query_Position_Velocity__run__next(void* _ctx) {
    struct Query_Position_Velocity__run* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        case 2: goto yield_2;
        default: return false;
    }

    ctx->_value = (struct tuple_u32_ptr_Position_ptr_Velocity) { ._0 = ctx->self->flags, ._1 = 0, ._2 = 0 }; ctx->_state = 1; return true; yield_1:;
    ctx->_state = -1; return false;
}
struct tuple_u32_ptr_Position_ptr_Velocity Query_Position_Velocity__run__value(void* ctx) { return ((struct Query_Position_Velocity__run*)ctx)->_value; }
struct trait_Iter_tuple_u32_ptr_Position_ptr_VelocityVTable Query_Position_Velocity__run__VTABLE__ITER = { .fn_next = Query_Position_Velocity__run__next, .fn_value = Query_Position_Velocity__run__value };

