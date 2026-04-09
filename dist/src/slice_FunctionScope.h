#ifndef PAVE_SLICE_FUNCTION_SCOPE
#define PAVE_SLICE_FUNCTION_SCOPE

#include <stdint.h>

struct FunctionScope;

struct slice_FunctionScope { struct FunctionScope* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_FunctionScope slice_FunctionScope__iter(struct slice_FunctionScope self);

#endif
