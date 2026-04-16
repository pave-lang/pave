#ifndef PAVE_ITER_ENUMERATE_REF_DIAGNOSTIC
#define PAVE_ITER_ENUMERATE_REF_DIAGNOSTIC

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_Diagnostic.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Diagnostic {
    uintptr_t index;
    struct Iter_ref_Diagnostic iter;
};

#include <tuple_usize_ref_Diagnostic.h>
struct IterEnumerate_ref_Diagnostic;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Diagnostic__next(struct IterEnumerate_ref_Diagnostic* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Diagnostic IterEnumerate_ref_Diagnostic__value(struct IterEnumerate_ref_Diagnostic* self);

#endif
