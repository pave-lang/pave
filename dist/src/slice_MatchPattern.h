#ifndef PAVE_SLICE_MATCH_PATTERN
#define PAVE_SLICE_MATCH_PATTERN

#include <analyzer/statement/MatchPattern.h>
#include <std/Iter_ref_MatchPattern.h>
struct slice_MatchPattern { struct MatchPattern* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_MatchPattern slice_MatchPattern__iter(struct slice_MatchPattern self);

#endif
