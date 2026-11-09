#ifndef PAVE_ITER_ENUMERATE_REF_FUNCTION_TEMP
#define PAVE_ITER_ENUMERATE_REF_FUNCTION_TEMP

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_FunctionTemp.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_FunctionTemp {
    uintptr_t index;
    struct Iter_ref_FunctionTemp iter;
};

#include <tuple_usize_ref_FunctionTemp.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_FunctionTemp__next(struct IterEnumerate_ref_FunctionTemp* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_FunctionTemp IterEnumerate_ref_FunctionTemp__value(struct IterEnumerate_ref_FunctionTemp* self);

#endif
