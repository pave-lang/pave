#ifndef PAVE_SLICE_INVOKE_ARGUMENT
#define PAVE_SLICE_INVOKE_ARGUMENT

#include <stdint.h>

struct InvokeArgument;

struct slice_InvokeArgument { struct InvokeArgument* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_InvokeArgument slice_InvokeArgument__iter(struct slice_InvokeArgument self);

#endif
