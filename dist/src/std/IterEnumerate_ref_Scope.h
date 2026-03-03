#ifndef PAVE_ITER_ENUMERATE_REF_SCOPE
#define PAVE_ITER_ENUMERATE_REF_SCOPE

#include <stdint.h>
#include <std/ArrayIter_ref_Scope.h>
#include <stdbool.h>

struct Scope;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Scope {
    uintptr_t index;
    struct ArrayIter_ref_Scope iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Scope__next(struct IterEnumerate_ref_Scope* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Scope IterEnumerate_ref_Scope__value(struct IterEnumerate_ref_Scope* self);

#endif
