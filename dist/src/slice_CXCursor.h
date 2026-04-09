#ifndef PAVE_SLICE_CXCURSOR
#define PAVE_SLICE_CXCURSOR

#include "clang-c/Index.h"
#include <stdint.h>

struct slice_CXCursor { CXCursor* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_CXCursor slice_CXCursor__iter(struct slice_CXCursor self);

#endif
