#ifndef PAVE_QUERY_VELOCITY_POSITION
#define PAVE_QUERY_VELOCITY_POSITION

#include <stdint.h>

struct Query_Velocity_Position {
    uint32_t flags;
};

#include <std/trait_Iter_tuple_u32_ptr_Velocity_ptr_Position.h>
#include <tuple_u32_ptr_Velocity_ptr_Position.h>
struct Query_Velocity_Position;
struct Query_Velocity_Position__run {
    int32_t _state;
    struct tuple_u32_ptr_Velocity_ptr_Position _value;

    struct Query_Velocity_Position* self;
};

#include <std/trait_Iter_tuple_u32_ptr_Velocity_ptr_Position.h>
struct tuple_u32_ptr_Velocity_ptr_Position Query_Velocity_Position__run__value(void* ctx);
extern struct trait_Iter_tuple_u32_ptr_Velocity_ptr_PositionVTable Query_Velocity_Position__run__VTABLE__ITER;

bool Query_Velocity_Position__run__next(void* _ctx);

#endif
