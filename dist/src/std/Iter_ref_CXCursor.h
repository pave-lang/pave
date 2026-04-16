#ifndef PAVE_ITER_REF_CXCURSOR
#define PAVE_ITER_REF_CXCURSOR

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>


#line 4 "src/std/Array.pv"
struct Iter_ref_CXCursor {
    intptr_t step;
    CXCursor* iter;
    CXCursor* start;
    CXCursor* end;
};

#include <std/Iter_ref_CXCursor.h>
#include <std/IterEnumerate_ref_CXCursor.h>
struct Iter_ref_CXCursor;

#line 12 "src/std/Array.pv"
struct Iter_ref_CXCursor Iter_ref_CXCursor__new(CXCursor* start, CXCursor* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_CXCursor Iter_ref_CXCursor__reverse(struct Iter_ref_CXCursor self);

#line 33 "src/std/Array.pv"
struct Iter_ref_CXCursor Iter_ref_CXCursor__skip(struct Iter_ref_CXCursor self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_CXCursor__next(struct Iter_ref_CXCursor* self);

#line 43 "src/std/Array.pv"
CXCursor* Iter_ref_CXCursor__value(struct Iter_ref_CXCursor* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_CXCursor Iter_ref_CXCursor__enumerate(struct Iter_ref_CXCursor self);

#endif
