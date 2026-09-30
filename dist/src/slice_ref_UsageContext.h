#ifndef PAVE_SLICE_REF_USAGE_CONTEXT
#define PAVE_SLICE_REF_USAGE_CONTEXT

#include <std/Iter_ref_ref_UsageContext.h>
struct UsageContext;
struct slice_ref_UsageContext { struct UsageContext** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_UsageContext slice_ref_UsageContext__iter(struct slice_ref_UsageContext self);

#endif
