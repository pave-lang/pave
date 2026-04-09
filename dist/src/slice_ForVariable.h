#ifndef PAVE_SLICE_FOR_VARIABLE
#define PAVE_SLICE_FOR_VARIABLE

#include <stdint.h>

struct ForVariable;

struct slice_ForVariable { struct ForVariable* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ForVariable slice_ForVariable__iter(struct slice_ForVariable self);

#endif
