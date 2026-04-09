#ifndef PAVE_SLICE_DIAGNOSTIC
#define PAVE_SLICE_DIAGNOSTIC

#include <stdint.h>

struct Diagnostic;

struct slice_Diagnostic { struct Diagnostic* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Diagnostic slice_Diagnostic__iter(struct slice_Diagnostic self);

#endif
