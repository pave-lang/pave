#ifndef PAVE_ITER_ENUMERATE_REF_FOR_VARIABLE
#define PAVE_ITER_ENUMERATE_REF_FOR_VARIABLE

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_ForVariable.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ForVariable {
    uintptr_t index;
    struct Iter_ref_ForVariable iter;
};

#include <tuple_usize_ref_ForVariable.h>
struct IterEnumerate_ref_ForVariable;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ForVariable__next(struct IterEnumerate_ref_ForVariable* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ForVariable IterEnumerate_ref_ForVariable__value(struct IterEnumerate_ref_ForVariable* self);

#endif
