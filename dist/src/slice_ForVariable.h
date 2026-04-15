#ifndef PAVE_SLICE_FOR_VARIABLE
#define PAVE_SLICE_FOR_VARIABLE

#include <analyzer/statement/ForVariable.h>
#include <std/Iter_ref_ForVariable.h>
struct slice_ForVariable { struct ForVariable* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ForVariable slice_ForVariable__iter(struct slice_ForVariable self);

#endif
