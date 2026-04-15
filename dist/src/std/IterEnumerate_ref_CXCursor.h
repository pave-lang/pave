#ifndef PAVE_ITER_ENUMERATE_REF_CXCURSOR
#define PAVE_ITER_ENUMERATE_REF_CXCURSOR

#include "clang-c/Index.h"
#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_CXCursor.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_CXCursor {
    uintptr_t index;
    struct Iter_ref_CXCursor iter;
};
struct IterEnumerate_ref_CXCursor;
#include <tuple_usize_ref_CXCursor.h>


#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_CXCursor__next(struct IterEnumerate_ref_CXCursor* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_CXCursor IterEnumerate_ref_CXCursor__value(struct IterEnumerate_ref_CXCursor* self);

#endif
