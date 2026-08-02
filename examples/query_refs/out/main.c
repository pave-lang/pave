#include <stdbool.h>

#include <assert.h>
#include <stdio.h>

#include <assert.h>
#include <stdio.h>
#include <query_refs/Query_ref_Position.h>
#include <query_refs/make_ref_query.h>
#include <query_refs/Query_ptr_Position.h>
#include <query_refs/make_ptr_query.h>
#include <i32.h>
#include <query_refs/Position.h>
#include <query_refs/Wrapper_ref_Position.h>
#include <query_refs/wrap_ref_Position.h>
#include <query_refs/Velocity.h>
#include <query_refs/Pair_i32_ref_Velocity.h>
#include <query_refs/add_ref_i32.h>
#include <query_refs/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Query_ref_Position refs = make_ref_query();
    struct Query_ptr_Position ptrs = make_ptr_query();

    assert(i32__Eq_i32__eq(refs.value, 42));
    assert(i32__Eq_i32__eq(ptrs.value, 84));

    printf("refs: %d\n", refs.value);
    printf("ptrs: %d\n", ptrs.value);

    struct Position pos = (struct Position) { .value = 7 };
    struct Wrapper_ref_Position wrapped = wrap_ref_Position(&pos);
    assert(i32__Eq_i32__eq(wrapped.value->value, 7));
    printf("wrapped: %d\n", wrapped.value->value);

    struct Velocity vel = (struct Velocity) { .value = 5 };
    struct Pair_i32_ref_Velocity pair = add_ref_i32(9, &vel);
    assert(i32__Eq_i32__eq(pair.a, 9));
    assert(i32__Eq_i32__eq(pair.b->value, 5));
    printf("pair: %d\n", pair.a);

    return 0;
}
