#ifndef PAVE_SLICE_MATCH_PATTERN
#define PAVE_SLICE_MATCH_PATTERN

#include <stdint.h>

struct MatchPattern;

struct slice_MatchPattern { struct MatchPattern* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_MatchPattern slice_MatchPattern__iter(struct slice_MatchPattern self);

#endif
