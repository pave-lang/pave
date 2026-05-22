#ifndef PAVE_QUERY_VELOCITY
#define PAVE_QUERY_VELOCITY

#include <stdint.h>

struct Query_Velocity {
    uint32_t flags;
};

#include <std/trait_Iter_tuple_u32_ptr_Velocity.h>
#include <tuple_u32_ptr_Velocity.h>
struct Query_Velocity;
#include <query/Query_Position.h>
#include <query/Query_Position_Velocity.h>

struct Query_Position_Velocity Query_Position__add_flag_Velocity_Position(struct Query_Velocity self);
#include <query/Query_Velocity.h>
#include <query/Query_Velocity_Position.h>

struct Query_Velocity_Position Query_Velocity__add_flag_Position_Velocity(struct Query_Velocity self);
struct Query_Velocity__run {
    int32_t _state;
    struct tuple_u32_ptr_Velocity _value;

    struct Query_Velocity* self;
};

#include <std/trait_Iter_tuple_u32_ptr_Velocity.h>
struct tuple_u32_ptr_Velocity Query_Velocity__run__value(void* ctx);
extern struct trait_Iter_tuple_u32_ptr_VelocityVTable Query_Velocity__run__VTABLE__ITER;

bool Query_Velocity__run__next(void* _ctx);

#endif
