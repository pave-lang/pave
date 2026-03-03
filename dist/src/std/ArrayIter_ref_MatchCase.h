#ifndef PAVE_ARRAY_ITER_REF_MATCH_CASE
#define PAVE_ARRAY_ITER_REF_MATCH_CASE

#include <stdint.h>
#include <stdbool.h>

struct MatchCase;
struct IterEnumerate_ref_MatchCase;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_MatchCase {
    intptr_t step;
    struct MatchCase* iter;
    struct MatchCase* start;
    struct MatchCase* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_MatchCase ArrayIter_ref_MatchCase__new(struct MatchCase* start, struct MatchCase* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_MatchCase ArrayIter_ref_MatchCase__reverse(struct ArrayIter_ref_MatchCase self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_MatchCase ArrayIter_ref_MatchCase__skip(struct ArrayIter_ref_MatchCase self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_MatchCase__next(struct ArrayIter_ref_MatchCase* self);

#line 43 "src/std/Array.pv"
struct MatchCase* ArrayIter_ref_MatchCase__value(struct ArrayIter_ref_MatchCase* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_MatchCase ArrayIter_ref_MatchCase__enumerate(struct ArrayIter_ref_MatchCase self);

#endif
