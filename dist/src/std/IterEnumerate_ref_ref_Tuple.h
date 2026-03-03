#ifndef PAVE_ITER_ENUMERATE_REF_REF_TUPLE
#define PAVE_ITER_ENUMERATE_REF_REF_TUPLE

#include <stdint.h>
#include <std/ArrayIter_ref_ref_Tuple.h>
#include <stdbool.h>

struct Tuple;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Tuple {
    uintptr_t index;
    struct ArrayIter_ref_ref_Tuple iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Tuple__next(struct IterEnumerate_ref_ref_Tuple* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Tuple IterEnumerate_ref_ref_Tuple__value(struct IterEnumerate_ref_ref_Tuple* self);

#endif
