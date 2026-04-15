#ifndef PAVE_ITER_ENUMERATE_REF_ELSE_STATEMENT
#define PAVE_ITER_ENUMERATE_REF_ELSE_STATEMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_ElseStatement.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ElseStatement {
    uintptr_t index;
    struct Iter_ref_ElseStatement iter;
};

struct IterEnumerate_ref_ElseStatement;
#include <tuple_usize_ref_ElseStatement.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ElseStatement__next(struct IterEnumerate_ref_ElseStatement* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ElseStatement IterEnumerate_ref_ElseStatement__value(struct IterEnumerate_ref_ElseStatement* self);

#endif
