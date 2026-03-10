#ifndef PAVE_ARRAY_ITER_REF_CXCURSOR
#define PAVE_ARRAY_ITER_REF_CXCURSOR

#include "clang-c/Index.h"
#include <stdint.h>
#include <stdbool.h>

struct IterEnumerate_ref_CXCursor;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_CXCursor {
    intptr_t step;
    CXCursor* iter;
    CXCursor* start;
    CXCursor* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_CXCursor ArrayIter_ref_CXCursor__new(CXCursor* start, CXCursor* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_CXCursor ArrayIter_ref_CXCursor__reverse(struct ArrayIter_ref_CXCursor self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_CXCursor ArrayIter_ref_CXCursor__skip(struct ArrayIter_ref_CXCursor self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_CXCursor__next(struct ArrayIter_ref_CXCursor* self);

#line 43 "src/std/Array.pv"
CXCursor* ArrayIter_ref_CXCursor__value(struct ArrayIter_ref_CXCursor* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_CXCursor ArrayIter_ref_CXCursor__enumerate(struct ArrayIter_ref_CXCursor self);

#endif
