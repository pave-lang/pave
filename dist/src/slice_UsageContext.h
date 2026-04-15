#ifndef PAVE_SLICE_USAGE_CONTEXT
#define PAVE_SLICE_USAGE_CONTEXT

#include <stdint.h>

struct UsageContext;

struct slice_UsageContext { struct UsageContext* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_UsageContext slice_UsageContext__iter(struct slice_UsageContext self);

#endif
