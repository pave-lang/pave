#include <stdint.h>
#include <stdbool.h>

#include <assert.h>
#include <stdio.h>

#include <stdio.h>
#include <assert.h>
#include <query/Query.h>
#include <query/Query_Position.h>
#include <query/Query_Position_Velocity.h>
#include <tuple_u32_ptr_Position_ptr_Velocity.h>
#include <query/Query_Velocity.h>
#include <query/Query_Velocity_Position.h>
#include <tuple_u32_ptr_Velocity_ptr_Position.h>
#include <query/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Query base = (struct Query) { .flags = 0 };
    struct Query_Position with_position = Query__add_flag_Position(base);
    struct Query_Position_Velocity with_both = Query_Position__add_flag_Velocity_Position(with_position);

    { struct Query_Position_Velocity__run __iter = (struct Query_Position_Velocity__run) { .self = &with_both };
    while (Query_Position_Velocity__run__next(&__iter)) {
        uint32_t flags = Query_Position_Velocity__run__value(&__iter)._0;
        struct Position* pos = Query_Position_Velocity__run__value(&__iter)._1;
        struct Velocity* vel = Query_Position_Velocity__run__value(&__iter)._2;

        printf("flags: %u\n", flags);
    } }

    assert(with_position.flags == 1);
    assert(with_both.flags == 3);

    printf("query flags: %u\n", with_both.flags);

    struct Query_Velocity reversed_with_position = Query__add_flag_Velocity(base);
    struct Query_Velocity_Position reversed_with_both = Query_Velocity__add_flag_Position_Velocity(reversed_with_position);

    { struct Query_Velocity_Position__run __iter = (struct Query_Velocity_Position__run) { .self = &reversed_with_both };
    while (Query_Velocity_Position__run__next(&__iter)) {
        uint32_t flags = Query_Velocity_Position__run__value(&__iter)._0;
        struct Velocity* vel = Query_Velocity_Position__run__value(&__iter)._1;
        struct Position* pos = Query_Velocity_Position__run__value(&__iter)._2;

        printf("flags: %u\n", flags);
    } }

    assert(reversed_with_position.flags == 1);
    assert(reversed_with_both.flags == 3);

    printf("query flags: %u\n", reversed_with_both.flags);

    return 0;
}
