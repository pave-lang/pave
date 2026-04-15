#ifndef PAVE_ITER_ENUMERATE_REF_SCOPE
#define PAVE_ITER_ENUMERATE_REF_SCOPE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_Scope.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Scope {
    uintptr_t index;
    struct Iter_ref_Scope iter;
};

struct IterEnumerate_ref_Scope;
#include <tuple_usize_ref_Scope.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Scope__next(struct IterEnumerate_ref_Scope* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Scope IterEnumerate_ref_Scope__value(struct IterEnumerate_ref_Scope* self);

#endif
