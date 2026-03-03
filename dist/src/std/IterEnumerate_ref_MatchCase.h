#ifndef PAVE_ITER_ENUMERATE_REF_MATCH_CASE
#define PAVE_ITER_ENUMERATE_REF_MATCH_CASE

#include <stdint.h>
#include <std/ArrayIter_ref_MatchCase.h>
#include <stdbool.h>

struct MatchCase;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_MatchCase {
    uintptr_t index;
    struct ArrayIter_ref_MatchCase iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_MatchCase__next(struct IterEnumerate_ref_MatchCase* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_MatchCase IterEnumerate_ref_MatchCase__value(struct IterEnumerate_ref_MatchCase* self);

#endif
