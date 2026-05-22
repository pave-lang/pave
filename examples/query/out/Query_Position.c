#include <stdint.h>

#include <assert.h>
#include <stdio.h>

#include <tuple_u32_ptr_Position.h>
#include <query/Query_Position.h>
#include <query/Query_Position.h>

#include <query/Query_Position.h>

bool Query_Position__run__next(void* _ctx) {
    struct Query_Position__run* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        default: return false;
    }

    ctx->_value = (struct tuple_u32_ptr_Position) { ._0 = ctx->self->flags, ._1 = 0 }; ctx->_state = 1; return true; yield_1:;
    ctx->_state = -1; return false;
}
struct tuple_u32_ptr_Position Query_Position__run__value(void* ctx) { return ((struct Query_Position__run*)ctx)->_value; }
struct trait_Iter_tuple_u32_ptr_PositionVTable Query_Position__run__VTABLE__ITER = { .fn_next = Query_Position__run__next, .fn_value = Query_Position__run__value };

