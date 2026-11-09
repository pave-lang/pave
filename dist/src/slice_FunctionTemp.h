#ifndef PAVE_SLICE_FUNCTION_TEMP
#define PAVE_SLICE_FUNCTION_TEMP

#include <compiler/FunctionTemp.h>
#include <std/Iter_ref_FunctionTemp.h>
struct slice_FunctionTemp { struct FunctionTemp* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_FunctionTemp slice_FunctionTemp__iter(struct slice_FunctionTemp self);

#endif
