#include <stdint.h>

#include <assert.h>
#include <stdio.h>

#include <query_refs/Query_ref_Position.h>
#include <query_refs/make_ref_query.h>

struct Query_ref_Position make_ref_query() {
    return (struct Query_ref_Position) { .value = 42 };
}
