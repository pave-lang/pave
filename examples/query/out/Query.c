#include <assert.h>
#include <stdio.h>

#include <query/Query.h>
#include <query/Query.h>

#include <query/Query.h>
#include <query/Query_Position.h>

struct Query_Position Query__add_flag_Position(struct Query self) {
    return (struct Query_Position) { .flags = self.flags | 1 };
}
#include <query/Query_Velocity.h>

struct Query_Velocity Query__add_flag_Velocity(struct Query self) {
    return (struct Query_Velocity) { .flags = self.flags | 1 };
}

bool Query__run__next(void* _ctx) {
    struct Query__run* ctx = _ctx;
    switch (ctx->_state) {
    case 0: break;
        case 1: goto yield_1;
        default: return false;
    }

    ctx->_value = ctx->self->flags; ctx->_state = 1; return true; yield_1:;
    ctx->_state = -1; return false;
}
uint32_t Query__run__value(void* ctx) { return ((struct Query__run*)ctx)->_value; }
struct trait_Iter_u32VTable Query__run__VTABLE__ITER = { .fn_next = Query__run__next, .fn_value = Query__run__value };

