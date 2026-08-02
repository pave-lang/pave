#include <assert.h>
#include <stdio.h>

#include <query_refs/Pair_i32_ref_Velocity.h>
#include <query_refs/Velocity.h>
#include <query_refs/add_ref_i32.h>

struct Pair_i32_ref_Velocity add_ref_i32(int32_t a, struct Velocity* v) {
    return (struct Pair_i32_ref_Velocity) { .a = a, .b = v };
}
