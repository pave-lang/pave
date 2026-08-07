#ifndef PAVE_QUERY
#define PAVE_QUERY

#include <stdint.h>

struct Query {
    uint32_t flags;
};

#include <std/trait_Iter_u32.h>
#include <query/Query.h>
#include <query/Query_Position.h>

struct Query_Position Query__add_flag_Position(struct Query self);
#include <query/Query_Velocity.h>

struct Query_Velocity Query__add_flag_Velocity(struct Query self);
struct Query__run {
    int32_t _state;
    uint32_t _value;

    struct Query* self;
};

#include <std/trait_Iter_u32.h>
uint32_t Query__run__value(void* ctx);
extern struct trait_Iter_u32VTable Query__run__VTABLE__ITER;

bool Query__run__next(void* _ctx);

#endif
