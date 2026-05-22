#include <stdint.h>

#include <assert.h>
#include <stdio.h>

#include <tuple_u32_ptr_Velocity.h>
#include <query/Query_Velocity.h>
#include <query/Query_Velocity.h>

#include <query/Query_Velocity.h>
#include <query/Query_Position_Velocity.h>
#include <query/Query_Position.h>

struct Query_Position_Velocity Query_Position__add_flag_Velocity_Position(struct Query_Velocity self) {
    return (struct Query_Position_Velocity) { .flags = self.flags | 2 };
}
#include <query/Query_Velocity_Position.h>

struct Query_Velocity_Position Query_Velocity__add_flag_Position_Velocity(struct Query_Velocity self) {
    return (struct Query_Velocity_Position) { .flags = self.flags | 2 };
}

bool Query_Velocity__run__next(void* _ctx) {
    struct Query_Velocity__run* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        case 2: goto yield_2;
        default: return false;
    }

    ctx->_value = (struct tuple_u32_ptr_Velocity) { ._0 = ctx->self->flags, ._1 = 0 }; ctx->_state = 1; return true; yield_1:;
    ctx->_state = -1; return false;
}
struct tuple_u32_ptr_Velocity Query_Velocity__run__value(void* ctx) { return ((struct Query_Velocity__run*)ctx)->_value; }
struct trait_Iter_tuple_u32_ptr_VelocityVTable Query_Velocity__run__VTABLE__ITER = { .fn_next = Query_Velocity__run__next, .fn_value = Query_Velocity__run__value };

