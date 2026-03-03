#ifndef PAVE_ITER_ENUMERATE_REF_DIAGNOSTIC
#define PAVE_ITER_ENUMERATE_REF_DIAGNOSTIC

#include <stdint.h>
#include <std/ArrayIter_ref_Diagnostic.h>
#include <stdbool.h>

struct Diagnostic;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Diagnostic {
    uintptr_t index;
    struct ArrayIter_ref_Diagnostic iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Diagnostic__next(struct IterEnumerate_ref_Diagnostic* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Diagnostic IterEnumerate_ref_Diagnostic__value(struct IterEnumerate_ref_Diagnostic* self);

#endif
