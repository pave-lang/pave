#ifndef PAVE_QUERY_POSITION
#define PAVE_QUERY_POSITION

#include <stdint.h>

struct Query_Position {
    uint32_t flags;
};

#include <std/trait_Iter_tuple_u32_ptr_Position.h>
#include <tuple_u32_ptr_Position.h>
struct Query_Position;
#include <query/Query_Position.h>
#include <query/Query_Position_Velocity.h>

struct Query_Position_Velocity Query_Position__add_flag_Velocity_Position(struct Query_Position self);
#include <query/Query_Velocity.h>
#include <query/Query_Velocity_Position.h>

struct Query_Velocity_Position Query_Velocity__add_flag_Position_Velocity(struct Query_Position self);
struct Query_Position__run {
    int32_t _state;
    struct tuple_u32_ptr_Position _value;

    struct Query_Position* self;
};

#include <std/trait_Iter_tuple_u32_ptr_Position.h>
struct tuple_u32_ptr_Position Query_Position__run__value(void* ctx);
extern struct trait_Iter_tuple_u32_ptr_PositionVTable Query_Position__run__VTABLE__ITER;

bool Query_Position__run__next(void* _ctx);

#endif
