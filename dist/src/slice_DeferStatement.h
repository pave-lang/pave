#ifndef PAVE_SLICE_DEFER_STATEMENT
#define PAVE_SLICE_DEFER_STATEMENT

#include <stdint.h>

struct DeferStatement;

struct slice_DeferStatement { struct DeferStatement* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_DeferStatement slice_DeferStatement__iter(struct slice_DeferStatement self);

#endif
