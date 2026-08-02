#include <stdint.h>

#include <assert.h>
#include <stdio.h>

#include <query_refs/Query_ptr_Position.h>
#include <query_refs/make_ptr_query.h>

struct Query_ptr_Position make_ptr_query() {
    return (struct Query_ptr_Position) { .value = 84 };
}
