#ifndef PAVE_ITER_REF_MATCH_PATTERN
#define PAVE_ITER_REF_MATCH_PATTERN

#include <stdint.h>
#include <stdbool.h>

struct MatchPattern;

#line 4 "src/std/Array.pv"
struct Iter_ref_MatchPattern {
    intptr_t step;
    struct MatchPattern* iter;
    struct MatchPattern* start;
    struct MatchPattern* end;
};

#include <std/Iter_ref_MatchPattern.h>
#include <std/IterEnumerate_ref_MatchPattern.h>
struct MatchPattern;
struct Iter_ref_MatchPattern;

#line 12 "src/std/Array.pv"
struct Iter_ref_MatchPattern Iter_ref_MatchPattern__new(struct MatchPattern* start, struct MatchPattern* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_MatchPattern Iter_ref_MatchPattern__reverse(struct Iter_ref_MatchPattern self);

#line 33 "src/std/Array.pv"
struct Iter_ref_MatchPattern Iter_ref_MatchPattern__skip(struct Iter_ref_MatchPattern self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_MatchPattern__next(struct Iter_ref_MatchPattern* self);

#line 43 "src/std/Array.pv"
struct MatchPattern* Iter_ref_MatchPattern__value(struct Iter_ref_MatchPattern* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_MatchPattern Iter_ref_MatchPattern__enumerate(struct Iter_ref_MatchPattern self);

#endif
