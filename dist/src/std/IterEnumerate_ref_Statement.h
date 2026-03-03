#ifndef PAVE_ITER_ENUMERATE_REF_STATEMENT
#define PAVE_ITER_ENUMERATE_REF_STATEMENT

#include <stdint.h>
#include <std/ArrayIter_ref_Statement.h>
#include <stdbool.h>

struct Statement;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Statement {
    uintptr_t index;
    struct ArrayIter_ref_Statement iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Statement__next(struct IterEnumerate_ref_Statement* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Statement IterEnumerate_ref_Statement__value(struct IterEnumerate_ref_Statement* self);

#endif
