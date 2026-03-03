#ifndef PAVE_SLICE_MATCH_CASE
#define PAVE_SLICE_MATCH_CASE

#include <stdint.h>

struct MatchCase;

struct slice_MatchCase { struct MatchCase* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_MatchCase slice_MatchCase__iter(struct slice_MatchCase self);

#endif
