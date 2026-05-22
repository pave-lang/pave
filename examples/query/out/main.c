#include <stdint.h>
#include <stdbool.h>

#include <assert.h>
#include <stdio.h>

#include <stdio.h>
#include <assert.h>
#include <query/Query.h>
#include <query/Query_Position.h>
#include <tuple_u32_ptr_Position.h>
#include <query/Query_Velocity.h>
#include <tuple_u32_ptr_Velocity.h>
#include <query/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Query base = (struct Query) { .flags = 0 };
    struct Query_Position positions = Query__add_flag_Position(base);

    { struct Query_Position__run __iter = (struct Query_Position__run) { .self = &positions };
    while (Query_Position__run__next(&__iter)) {
        uint32_t flags = Query_Position__run__value(&__iter)._0;
        struct Position* pos = Query_Position__run__value(&__iter)._1;

        printf("flags: %u\n", flags);
    } }

    assert(positions.flags == 1);

    printf("query flags: %u\n", positions.flags);

    struct Query_Velocity velocities = Query__add_flag_Velocity(base);

    { struct Query_Velocity__run __iter = (struct Query_Velocity__run) { .self = &velocities };
    while (Query_Velocity__run__next(&__iter)) {
        uint32_t flags = Query_Velocity__run__value(&__iter)._0;
        struct Velocity* vel = Query_Velocity__run__value(&__iter)._1;

        printf("flags: %u\n", flags);
    } }

    assert(velocities.flags == 1);

    printf("query flags: %u\n", velocities.flags);

    return 0;
}
