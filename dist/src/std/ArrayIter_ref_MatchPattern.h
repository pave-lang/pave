#ifndef PAVE_ARRAY_ITER_REF_MATCH_PATTERN
#define PAVE_ARRAY_ITER_REF_MATCH_PATTERN

#include <stdint.h>
#include <stdbool.h>

struct MatchPattern;
struct IterEnumerate_ref_MatchPattern;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_MatchPattern {
    intptr_t step;
    struct MatchPattern* iter;
    struct MatchPattern* start;
    struct MatchPattern* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_MatchPattern ArrayIter_ref_MatchPattern__new(struct MatchPattern* start, struct MatchPattern* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_MatchPattern ArrayIter_ref_MatchPattern__reverse(struct ArrayIter_ref_MatchPattern self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_MatchPattern ArrayIter_ref_MatchPattern__skip(struct ArrayIter_ref_MatchPattern self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_MatchPattern__next(struct ArrayIter_ref_MatchPattern* self);

#line 43 "src/std/Array.pv"
struct MatchPattern* ArrayIter_ref_MatchPattern__value(struct ArrayIter_ref_MatchPattern* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_MatchPattern ArrayIter_ref_MatchPattern__enumerate(struct ArrayIter_ref_MatchPattern self);

#endif
