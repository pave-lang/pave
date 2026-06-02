#ifndef PAVE_SLICE_COMPLETION_INFO
#define PAVE_SLICE_COMPLETION_INFO

#include <analyzer/CompletionInfo.h>
#include <std/Iter_ref_CompletionInfo.h>
struct slice_CompletionInfo { struct CompletionInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_CompletionInfo slice_CompletionInfo__iter(struct slice_CompletionInfo self);

#endif
