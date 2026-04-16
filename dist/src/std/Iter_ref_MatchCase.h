#ifndef PAVE_ITER_REF_MATCH_CASE
#define PAVE_ITER_REF_MATCH_CASE

#include <stdint.h>
#include <stdbool.h>

struct MatchCase;

#line 4 "src/std/Array.pv"
struct Iter_ref_MatchCase {
    intptr_t step;
    struct MatchCase* iter;
    struct MatchCase* start;
    struct MatchCase* end;
};

#include <std/Iter_ref_MatchCase.h>
#include <std/IterEnumerate_ref_MatchCase.h>
struct MatchCase;
struct Iter_ref_MatchCase;

#line 12 "src/std/Array.pv"
struct Iter_ref_MatchCase Iter_ref_MatchCase__new(struct MatchCase* start, struct MatchCase* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_MatchCase Iter_ref_MatchCase__reverse(struct Iter_ref_MatchCase self);

#line 33 "src/std/Array.pv"
struct Iter_ref_MatchCase Iter_ref_MatchCase__skip(struct Iter_ref_MatchCase self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_MatchCase__next(struct Iter_ref_MatchCase* self);

#line 43 "src/std/Array.pv"
struct MatchCase* Iter_ref_MatchCase__value(struct Iter_ref_MatchCase* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_MatchCase Iter_ref_MatchCase__enumerate(struct Iter_ref_MatchCase self);

#endif
