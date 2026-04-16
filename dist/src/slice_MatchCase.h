#ifndef PAVE_SLICE_MATCH_CASE
#define PAVE_SLICE_MATCH_CASE

#include <analyzer/statement/MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
struct slice_MatchCase { struct MatchCase* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_MatchCase slice_MatchCase__iter(struct slice_MatchCase self);

#endif
