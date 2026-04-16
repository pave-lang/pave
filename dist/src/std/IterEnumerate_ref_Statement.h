#ifndef PAVE_ITER_ENUMERATE_REF_STATEMENT
#define PAVE_ITER_ENUMERATE_REF_STATEMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_Statement.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Statement {
    uintptr_t index;
    struct Iter_ref_Statement iter;
};

#include <tuple_usize_ref_Statement.h>
struct IterEnumerate_ref_Statement;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Statement__next(struct IterEnumerate_ref_Statement* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Statement IterEnumerate_ref_Statement__value(struct IterEnumerate_ref_Statement* self);

#endif
