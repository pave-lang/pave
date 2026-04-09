#ifndef PAVE_ITER_ENUMERATE_REF_MATCH_PATTERN
#define PAVE_ITER_ENUMERATE_REF_MATCH_PATTERN

#include <stdint.h>
#include <std/Iter_ref_MatchPattern.h>
#include <stdbool.h>

struct MatchPattern;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_MatchPattern {
    uintptr_t index;
    struct Iter_ref_MatchPattern iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_MatchPattern__next(struct IterEnumerate_ref_MatchPattern* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_MatchPattern IterEnumerate_ref_MatchPattern__value(struct IterEnumerate_ref_MatchPattern* self);

#endif
