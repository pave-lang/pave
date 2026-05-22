#ifndef PAVE_QUERY_POSITION_VELOCITY
#define PAVE_QUERY_POSITION_VELOCITY

#include <stdint.h>

struct Query_Position_Velocity {
    uint32_t flags;
};

#include <std/trait_Iter_tuple_u32_ptr_Position_ptr_Velocity.h>
#include <tuple_u32_ptr_Position_ptr_Velocity.h>
struct Query_Position_Velocity;
struct Query_Position_Velocity__run {
    int32_t _state;
    struct tuple_u32_ptr_Position_ptr_Velocity _value;

    struct Query_Position_Velocity* self;
};

#include <std/trait_Iter_tuple_u32_ptr_Position_ptr_Velocity.h>
struct tuple_u32_ptr_Position_ptr_Velocity Query_Position_Velocity__run__value(void* ctx);
extern struct trait_Iter_tuple_u32_ptr_Position_ptr_VelocityVTable Query_Position_Velocity__run__VTABLE__ITER;

bool Query_Position_Velocity__run__next(void* _ctx);

#endif
