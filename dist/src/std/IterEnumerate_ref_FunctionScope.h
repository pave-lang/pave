#ifndef PAVE_ITER_ENUMERATE_REF_FUNCTION_SCOPE
#define PAVE_ITER_ENUMERATE_REF_FUNCTION_SCOPE

#include <stdint.h>
#include <std/Iter_ref_FunctionScope.h>
#include <stdbool.h>

struct FunctionScope;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_FunctionScope {
    uintptr_t index;
    struct Iter_ref_FunctionScope iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_FunctionScope__next(struct IterEnumerate_ref_FunctionScope* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_FunctionScope IterEnumerate_ref_FunctionScope__value(struct IterEnumerate_ref_FunctionScope* self);

#endif
