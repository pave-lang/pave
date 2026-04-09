#ifndef PAVE_ITER_ENUMERATE_REF_PARAMETER
#define PAVE_ITER_ENUMERATE_REF_PARAMETER

#include <stdint.h>
#include <std/Iter_ref_Parameter.h>
#include <stdbool.h>

struct Parameter;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Parameter {
    uintptr_t index;
    struct Iter_ref_Parameter iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Parameter__next(struct IterEnumerate_ref_Parameter* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Parameter IterEnumerate_ref_Parameter__value(struct IterEnumerate_ref_Parameter* self);

#endif
