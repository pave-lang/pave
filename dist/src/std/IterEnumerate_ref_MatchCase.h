#ifndef PAVE_ITER_ENUMERATE_REF_MATCH_CASE
#define PAVE_ITER_ENUMERATE_REF_MATCH_CASE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_MatchCase.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_MatchCase {
    uintptr_t index;
    struct Iter_ref_MatchCase iter;
};

struct IterEnumerate_ref_MatchCase;
#include <tuple_usize_ref_MatchCase.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_MatchCase__next(struct IterEnumerate_ref_MatchCase* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_MatchCase IterEnumerate_ref_MatchCase__value(struct IterEnumerate_ref_MatchCase* self);

#endif
