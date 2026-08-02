#include <assert.h>
#include <stdio.h>

#include <query_refs/Wrapper_ref_Position.h>
#include <query_refs/Position.h>
#include <query_refs/wrap_ref_Position.h>

struct Wrapper_ref_Position wrap_ref_Position(struct Position* value) {
    return (struct Wrapper_ref_Position) { .value = value };
}
