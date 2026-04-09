#ifndef PAVE_ITER_ENUMERATE_REF_REF_EXPRESSION
#define PAVE_ITER_ENUMERATE_REF_REF_EXPRESSION

#include <stdint.h>
#include <std/Iter_ref_ref_Expression.h>
#include <stdbool.h>

struct Expression;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Expression {
    uintptr_t index;
    struct Iter_ref_ref_Expression iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Expression__next(struct IterEnumerate_ref_ref_Expression* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Expression IterEnumerate_ref_ref_Expression__value(struct IterEnumerate_ref_ref_Expression* self);

#endif
