#ifndef PAVE_ITER_ENUMERATE_REF_DEFER_STATEMENT
#define PAVE_ITER_ENUMERATE_REF_DEFER_STATEMENT

#include <stdint.h>
#include <std/ArrayIter_ref_DeferStatement.h>
#include <stdbool.h>

struct DeferStatement;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_DeferStatement {
    uintptr_t index;
    struct ArrayIter_ref_DeferStatement iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_DeferStatement__next(struct IterEnumerate_ref_DeferStatement* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_DeferStatement IterEnumerate_ref_DeferStatement__value(struct IterEnumerate_ref_DeferStatement* self);

#endif
