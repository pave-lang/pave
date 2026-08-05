#ifndef PAVE_ITER_ENUMERATE_REF_PREPROCESSOR_ELSE_IF
#define PAVE_ITER_ENUMERATE_REF_PREPROCESSOR_ELSE_IF

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_PreprocessorElseIf.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_PreprocessorElseIf {
    uintptr_t index;
    struct Iter_ref_PreprocessorElseIf iter;
};

#include <tuple_usize_ref_PreprocessorElseIf.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_PreprocessorElseIf__next(struct IterEnumerate_ref_PreprocessorElseIf* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_PreprocessorElseIf IterEnumerate_ref_PreprocessorElseIf__value(struct IterEnumerate_ref_PreprocessorElseIf* self);

#endif
